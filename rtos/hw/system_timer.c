#include "./include/system_timer.h"

// Control/Status register bits (one per channel)
#define CS_M0   (1 << 0)
#define CS_M1   (1 << 1)
#define CS_M2   (1 << 2)
#define CS_M3   (1 << 3)

volatile unsigned int tick_count = 0;   // Global tick counter

// -------------------------------------------------
// Reads the Control/Status register (for debugging)
// -------------------------------------------------
void control_status(void) {
    volatile unsigned int status = CS;
    (void)status;
}

// -------------------------------------------------
// Set compare value for a given channel (0–3)
// -------------------------------------------------
void timer_set_compare(int channel, unsigned int value) {
    switch (channel) {
        case 0: C0 = value; break;
        case 1: C1 = value; break;
        case 2: C2 = value; break;
        case 3: C3 = value; break;
        default: break; // invalid channel
    }
}

void system_delay(unsigned int msec) {
    unsigned int start = tick_count;
    while ((tick_count - start) < msec) { }
}

void timer_init(void) {
    unsigned int now = CLO;
    unsigned int value = now + 1000;   // First interrupt in 1000 µs = 1 ms
    timer_set_compare(1,value);
    CS = CS_M1;        // Clear any pending match
}

void c_irq_handler(void) {
    if (CS & CS_M1) {          // Check channel 1
        CS = CS_M1;            // Acknowledge interrupt
        tick_count++;          // Increment tick
        timer_set_compare(1,C1+1000);            // Next tick in 1 ms
    }
}
