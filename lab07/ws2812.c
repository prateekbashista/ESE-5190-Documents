/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "D:\pico\pico-sdk\src\boards\include\boards\adafruit_qtpy_rp2040.h"

#define IS_RGBW true

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif
#define PICO_DEFAULT_WS2812_POWER_PIN 11
#define BOOT 21

typedef struct
{
    uint32_t stat;
} boot_stat;

void set_neopixel_color(uint32_t color)
{
    // your implementation goes here
    uint32_t rc = color >> 16;
    uint32_t gc = color << 16;
    gc = gc >> 24;
    uint32_t bc = color << 24;
    bc = bc >> 24;
    uint32_t color_new = ((rc << 8) | (gc << 16) | (bc));
    pio_sm_put_blocking(pio0, 0, color_new << 8u);
}

int main()
{
    // set_sys_clock_48();
    const uint POW_PIN = PICO_DEFAULT_WS2812_POWER_PIN;
    const uint boot = BOOT;
    gpio_init(POW_PIN);
    gpio_set_dir(POW_PIN, GPIO_OUT);
    gpio_put(POW_PIN, 1);
    gpio_init(boot);
    gpio_set_dir(boot, GPIO_IN);
    stdio_init_all();

    boot_stat press;
    press.stat = 0x00000000;

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    int sm1 = 1;
    uint offset = pio_add_program(pio, &ws2812_program);
    uint offset1 = pio_add_program(pio, &bootpin_program);


    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    bootpin_program_init(pio,sm1,offset1,boot);
    const int y;
    int t = 0;
    int i = 0;
    unsigned char play[10000];

    while (!stdio_usb_connected())
        ;

     int result=0;
    while (1)
    {
        
        char key = getchar_timeout_us(2000);
        

        if (key == 'b')
        {    
           
            //sleep_ms(1000);
            result = (uint8_t)pio_sm_get(pio,sm1);
            printf("%d\n", result);
            printf("In B mode: \n");
            while ((uint8_t)pio_sm_get(pio,sm1)==0)
            {
                play[i] = 1;
               // printf("%d\n", play[i]);
                i++;
                printf("%d\n", result);
                //result = (uint8_t)pio_sm_get(pio,sm1);
                sleep_ms(100);
            }
        }

        else if (key == 'p')
        {
            //  printf(i);
           

            // printf("This is P:%d\n", p);
            for(int j=0;j<i;j++)
            {
                if(play[j]==1){
                    set_neopixel_color(0xFF00FF);
                    sleep_ms(500);
                    set_neopixel_color(0);
                }
                else{
                    set_neopixel_color(0);
                    sleep_ms(50);
                }
                sleep_ms(50);
            }
        }
        else
        {
            play[i] = 0;
            i++;
            printf("0\n");
        }

        /////////////////////////////////////////////////////////
        //    char key =  getchar_timeout_us(2000);

        //    if(key == 'b')
        //    {
        //        sleep_ms(1000);
        //         while(!(t==gpio_get(boot))){
        //             printf(t);
        //             play[i] = 1;
        //             printf(play[i]);
        //             i++;
        //             sleep_ms(50);
        //             //replace sleep with check
        //         }
        //    }
        //     else if(key == 'p' )
        //     {
        //         for(int j=0;j<i;j++)
        //         {
        //             if(play[j]==1){
        //                 set_neopixel_color(0xFF00FF);
        //                 sleep_ms(50);
        //             }
        //             else{
        //                 set_neopixel_color(0);
        //                 sleep_ms(50);
        //             }
        //         }
        //     }
        //     else
        //     {
        //         play[i] = 0;
        //     }
        /*
               if(gpio_get(boot)!=0)
               {
                press.stat = 0x00000001;
               }
               else
               {
                press.stat = 0x00000000;
               }




               if(press.stat){
                set_neopixel_color(0xFF00FF);
                sleep_ms(500);
                set_neopixel_color(0);
               }
              */
        sleep_ms(100);
    }
}
