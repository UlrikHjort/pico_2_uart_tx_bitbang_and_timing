/**************************************************************************
--           PICO2 RISC-V Sierpinski UART Bitbang
-- 
--           Copyright (C) 2025 By Ulrik Hørlyk Hjort
--
--  This Program is Free Software; You Can Redistribute It and/or
--  Modify It Under The Terms of The GNU General Public License
--  As Published By The Free Software Foundation; Either Version 2
--  of The License, or (at Your Option) Any Later Version.
--
--  This Program is Distributed in The Hope That It Will Be Useful,
--  But WITHOUT ANY WARRANTY; Without Even The Implied Warranty of
--  MERCHANTABILITY or FITNESS for A PARTICULAR PURPOSE.  See The
--  GNU General Public License for More Details.
--
-- You Should Have Received A Copy of The GNU General Public License
-- Along with This Program; if not, See <Http://Www.Gnu.Org/Licenses/>.
***************************************************************************/
#include <stdint.h>
#include "pico/stdio/driver.h"
#include "pico/stdlib.h"

#define LOW 0
#define HIGH 1

/* UART configutation:
 * 8N1
 * 8 data bits, No parity, 1 stop bit
 */


uint32_t bit_time_us = 0;
uint tx_pin = 0;


void send_bit(uint8_t bit) {
	gpio_put(tx_pin, bit);
	sleep_us(bit_time_us);
}


void uart_bitbang_tx(uint8_t byte) {
    // Start bit
    send_bit(0);

    // Data bits (LSB first)
    for (int i = 0; i < 8; i++) {
        bool bit = (byte >> i) & 1;
        send_bit(bit);
    }

    // Stop bit
    send_bit(1);
}



static void printf_redirect(const char *buf, int length) {
    for (int i = 0; i < length; i++) {
        uart_bitbang_tx(*(buf+i));
        
    }
}


static stdio_driver_t uart_bitbang_stdio = {
    .out_chars = printf_redirect,
    .in_chars = NULL,  
    .next = NULL,
};


void init_uart(uint32_t baud_rate, uint tx_pin_) {
	tx_pin = tx_pin_;
	bit_time_us = (1000000 / baud_rate);
    gpio_init(tx_pin);
    gpio_set_dir(tx_pin, GPIO_OUT);	
	stdio_set_driver_enabled(&uart_bitbang_stdio, true);
}


