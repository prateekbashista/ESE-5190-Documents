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


typedef          uint32_t   VALUE;
typedef volatile uint32_t * ADDRESS;

VALUE register_read(ADDRESS address) {
    return *address;
}

void register_write(ADDRESS address, VALUE value) {
    *address = value;
}

#define QTPY_REG ((volatile uint32_t *)(IO_BANK0_BASE + 0x00C))

int main() {
    //set_sys_clock_48();
   
    uint32_t value;
    while(!stdio_usb_connected());

    while (1) {

        printf("Enter register to access: ");
        value = register_read(QTPY_REG);
        printf("\n %x", value);

        uint32_t reg_write;
        printf("Enter the value to be written:\n");
        scanf("%x", &reg_write);
        register_write(QTPY_REG, reg_write);

        printf("Enter register to access: ");
        value = register_read(QTPY_REG);
        printf("\n %x", value);

      sleep_ms(1000);
    }
}
