#ifndef UART_H
#define UART_H

#include <stdint.h>

// MMIO base for Raspberry Pi 3
#ifndef PERIPHERAL_BASE
#define PERIPHERAL_BASE 0x3F000000UL
#endif

#define UART0_BASE      (PERIPHERAL_BASE + 0x201000)

#define UART_DR   (*(volatile uint32_t *)(UART0_BASE + 0x00))
#define UART_FR   (*(volatile uint32_t *)(UART0_BASE + 0x18))
#define UART_IBRD (*(volatile uint32_t *)(UART0_BASE + 0x24))
#define UART_FBRD (*(volatile uint32_t *)(UART0_BASE + 0x28))
#define UART_LCRH (*(volatile uint32_t *)(UART0_BASE + 0x2C))
#define UART_CR   (*(volatile uint32_t *)(UART0_BASE + 0x30))
#define UART_IMSC (*(volatile uint32_t *)(UART0_BASE + 0x38))
#define UART_ICR  (*(volatile uint32_t *)(UART0_BASE + 0x44))

void uart_init(void);
void uart_putc(unsigned char c);
unsigned char uart_getc(void);
void uart_puts(const char *s);

#endif
