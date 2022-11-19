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

void blink_pin_forever(PIO pio, uint sm, uint offset, uint pin) {
    blink_program_init(pio, sm, offset, pin);
    pio_sm_set_enabled(pio, sm, true);
    pio->txf[sm] = 5000;

}

int board_mode()
{
    const uint red1 = 26;
    const uint blue2 = 4;
    const uint red_b = 29;
    const uint blue_b = 6;

    gpio_init(red1);
    gpio_init(red_b);
    gpio_init(blue2);
    gpio_init(blue_b);

    gpio_set_dir(red1, GPIO_OUT);
    gpio_set_dir(blue2, GPIO_OUT);
    gpio_set_dir(red_b, GPIO_IN);
    gpio_set_dir(blue_b, GPIO_IN);
    //gpio_put(POW_PIN, 1);


    stdio_init_all();

    PIO pio = pio0;
    int sm2 = 2;
    int sm1 = 1;
    int sm0 = 0;
    uint offset = pio_add_program(pio, &blink_program);
    uint offset1 = pio_add_program(pio, &bootpin1_program);
    bootpin1_program_init(pio,sm1,offset1,red_b);

    uint offset2 = pio_add_program(pio, &bootpin2_program);
    bootpin2_program_init(pio,sm2,offset2,blue_b);

    while (1) {

       if(((uint8_t)pio_sm_get(pio, sm1)) == 1)
       {
        blink_pin_forever(pio, sm0, offset, red1);
        //gpio_put(blue,0);
        return -1;
       }
       else if(((uint8_t)pio_sm_get(pio, sm2)) == 1)
       {
        blink_pin_forever(pio, sm0, offset, blue2);
        //gpio_put(red,0);
        return -1;
       }
    
    }
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
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    const int y;
    int t = 0;
    int i = 0;
    unsigned char play[10000];

    while (!stdio_usb_connected());

    while (1)
    {

        char key = getchar_timeout_us(2000);

        if (key == 'b')
        {
            sleep_ms(1000);
            while (!gpio_get(boot))
            {
                play[i] = 1;
                printf("%d\n", play[i]);
                i++;
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
                    sleep_ms(500);
                }
                else{
                    set_neopixel_color(0);
                    sleep_ms(500);
                }
                sleep_ms(50);
            }
        }

        else if (key == 's')
        {
            //  printf(i);
           

            // printf("This is P:%d\n", p);
            for(int j=0;j<i;j++)
            {
                if(play[j]==1){
                    set_neopixel_color(0xFF00FF);
                    sleep_ms(1000);
                    set_neopixel_color(0);
                    sleep_ms(1000);
                }
                else{
                    set_neopixel_color(0);
                    sleep_ms(1000);
                }
                sleep_ms(50);
            }
        }
        else if (key == 'f')
        {
            //  printf(i);
           

            // printf("This is P:%d\n", p);
            for(int j=0;j<i;j++)
            {
                if(play[j]==1){
                    set_neopixel_color(0xFF00FF);
                    sleep_ms(50);
                    set_neopixel_color(0);
                    sleep_ms(50);
                }
                else{
                    set_neopixel_color(0);
                    sleep_ms(50);
                }
                sleep_ms(50);
            }
        }
        else if (key == 'g')
        {
            int var =  board_mode();
            if(var==-1)
            {
                break;
            }
        }
        else
        {
            play[i] = 0;
            i++;
            printf("0\n");
        }

        sleep_ms(100);
    }
}
