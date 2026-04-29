#include "./include/uart.h"

// Initialize PL011 UART0
void uart_init(void) {
    // Disable UART
    UART_CR = 0x0;

    // Clear interrupts
    UART_ICR = 0x7FF;

    // Set baud rate for 115200 (UARTCLK=48MHz)
    // BAUDDIV = 48,000,000 / (16*115200) ≈ 26.0417
    UART_IBRD = 26;
    UART_FBRD = 3;

    // Line control: 8 bits, no parity, 1 stop, enable FIFO
    UART_LCRH = (1 << 4) | (3 << 5);

    // Enable UART, TX, RX
    UART_CR = (1 << 0) | (1 << 8) | (1 << 9);
}

// Send one character
void uart_putc(unsigned char c) {
    while (UART_FR & (1 << 5)) { } // Wait if TX FIFO full
    UART_DR = c;
}

// Receive one character
unsigned char uart_getc(void) {
    while (UART_FR & (1 << 4)) { } // Wait if RX FIFO empty
    return (unsigned char)(UART_DR & 0xFF);
}

// Send string
void uart_puts(const char *s) {
    while (*s) {
        if (*s == '\n') uart_putc('\r'); // CR before LF
        uart_putc(*s++);
    }
}
