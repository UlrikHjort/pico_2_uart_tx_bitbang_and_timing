# PICO 2 Bitbaning TX UART and timing module

Simple bitbanging tx only uart for debug printout. Redirects printf to the uart bitbang gpio selected.

### Uart module usage:
	Set baudrate and tx gpio pin with init_uart.

	Example: Set baudrate 19200 and tx pin to GPIO2:

		init_uart(19200,2);

    Use whatever USB to serial TTL adapter to connect to PC. 

### Timing module usage:
	   Use TIME_MEASURE_US (for microseconds) or TIME_MEASURE_MS (for milliseconds) around the function to time,
	   or use TIME_START and TIME_US_STOP(label) (for microseconds) or TIME_MS_STOP(label) (for milliseconds) to time
	   a block.

See main.c for example of usage. 

	   
