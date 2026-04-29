// hw/include/interrupts.h
#include "common.h"
#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#define PERIPHERAL_BASE 0x3F000000
#define INTERRUPT_BASE (PERIPHERAL_BASE + 0xB000)

#define IRQ_PENDING1 REG32(INTERRUPT_BASE + 0x204)
#define IRQ_PENDING2 REG32(INTERRUPT_BASE + 0x208)
#define IRQ_ENABLE1 REG32(INTERRUPT_BASE + 0x210)
#define IRQ_ENABLE2 REG32(INTERRUPT_BASE + 0x214)
#define IRQ_DISABLE1 REG32(INTERRUPT_BASE + 0x21C)

// ------------------------
// Timer IRQs (bit masks for system timer channels)
// ------------------------
#define IRQ_TIMER0 (1 << 0)
#define IRQ_TIMER1 (1 << 1)   // channel 1 — matches your C handler
#define IRQ_TIMER2 (1 << 2)
#define IRQ_TIMER3 (1 << 3)


int irq_is_pending(unsigned int irq_mask);
void irq_disable(unsigned int irq_mask);
void irq_enable(unsigned int irq_mask);

#endif
