/**************************************************************************
--           PICO2 RISC-V Sierpinski UART Bitbang main test
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
#include "pico/stdlib.h"
#include <stdint.h>
#include <stdio.h>

#include "timing.h"
#include "uart_bitbang.h"

#define UART_TX_PIN 2

/*
 * test and usage demonstation og the timing and uart modules 
 */
int main() {
	init_uart(19200,UART_TX_PIN);
	
	while(1) {

		TIME_MEASURE_US(sleep_ms(500));
		TIME_MEASURE_MS(sleep_ms(500));

		
		TIME_START();
		sleep_ms(1000);
		TIME_US_STOP("US");


		TIME_START();
		sleep_ms(100);
		TIME_MS_STOP("");		
	}
}
