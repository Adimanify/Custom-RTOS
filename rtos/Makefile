# =========================
# Minimal Makefile for RPi Baremetal RTOS
# =========================

# Tools
CC      = aarch64-linux-gnu-gcc
OBJCOPY = aarch64-linux-gnu-objcopy

# Compilation flags
CFLAGS  = -Wall -O2 -ffreestanding -nostdlib -nostartfiles \
          -I. -Ihw -Ihw/include -Irtos -Iapp
LDFLAGS = -T linker.ld -nostdlib

# Source files
SRC_C   = app/kernel_main.c \
          hw/gpio.c \
          hw/system_timer.c \
          hw/interrupts.c \
          hw/uart.c \
          rtos/rtos.c

SRC_ASM = boot/boot.S \
          boot/vectors.S \
          boot/irq_handler.S

# Object files
OBJ_C   = $(SRC_C:.c=.o)
OBJ_ASM = $(SRC_ASM:.S=.o)
OBJ     = $(OBJ_C) $(OBJ_ASM)

# Target names
TARGET = kernel

# Default target
all: $(TARGET)8.img

# Compile C files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble Assembly files
%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

# Link objects into ELF (use gcc instead of ld)
$(TARGET).elf: $(OBJ) linker.ld
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ)

# Convert ELF → raw binary
$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# Rename binary → kernel8.img (for Raspberry Pi AArch64)
$(TARGET)8.img: $(TARGET).bin
	cp $< $@

# Clean build artifacts
clean:
	rm -f $(OBJ) $(TARGET).elf $(TARGET).bin $(TARGET)8.img
