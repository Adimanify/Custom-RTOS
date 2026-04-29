#include "../rtos/rtos.h"
#include "../hw/include/gpio.h"
#include "../hw/include/system_timer.h"
#include "../hw/include/interrupts.h"
#include "../hw/include/uart.h"

#define LED_PIN 4   // GPIO17 = pin 11 on RPi header


void kernel_main(void) {
    uart_init();
    uart_puts("Hello, bare-metal world!\n");

    while (1) {
        char c = uart_getc(); // Wait for input
        uart_putc(c);         // Echo back
    }
}

