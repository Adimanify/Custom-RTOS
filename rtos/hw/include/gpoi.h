#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define MMIO_BASE   0x3F000000UL   // Pi 2/3
// #define MMIO_BASE 0xFE000000UL   // Pi 4, uncomment if needed
#define GPIO_BASE   (MMIO_BASE + 0x200000)

#define GPFSEL0     ((volatile uint32_t*)(GPIO_BASE + 0x00))
#define GPFSEL1     ((volatile uint32_t*)(GPIO_BASE + 0x04))
#define GPSET0      ((volatile uint32_t*)(GPIO_BASE + 0x1C))
#define GPCLR0      ((volatile uint32_t*)(GPIO_BASE + 0x28))
#define GPLEV0      ((volatile uint32_t*)(GPIO_BASE + 0x34))

void gpio_init_output(int pin);
void gpio_set(int pin);
void gpio_clear(int pin);
int  gpio_read(int pin);

#endif
