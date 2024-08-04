#include <stdio.h>
#include "pin.h"
#include "bit.h"
#define PD3 2
#define SLOTS 8
#define LITTLE_ENDIAN

static unsigned int toggle_pin(unsigned int reg, int pin)
{
    reg ^= (1 << pin);
    return reg;
}

static unsigned int pin_off(unsigned int reg, int pin)
{
    reg &= ~(1 << pin);
    return reg;
}

static unsigned int pin_on(unsigned int reg, int pin)
{
    reg |= (1 << pin);
    return reg;
}

static unsigned int pin_peek(unsigned int reg, int pin)
{
    int bit = (reg & (1 << pin)) >> pin;
    return bit;
}

void endianness(unsigned int x)
{
    unsigned int le_value = x;            // A 32-bit integer in little endian
    unsigned int be_value = swap_endian(le_value); // Convert to big endian
    printf("Little Endian: 0x%08x\n", le_value);
    printf("Big Endian: 0x%08x\n", be_value);
}

void print_binary(int reg, int pin)
{
    printf("binary register: ");
#ifdef LITTLE_ENDIAN
    for (int i = SLOTS - 1; i >= 0; i--)
#else
    for (int i = 0; i < SLOTS; i++)
#endif
    {
        int bit = pin_peek(reg, i);
        if (i == pin)
        {
            if (bit == 0)
                printf("\x1b[38;5;196m%d\x1b[0m", bit);
            else
                printf("\x1b[38;5;40m%d\x1b[0m", bit);
        }
        else
            printf("%d", bit);
    }
    printf("\n");
}

void pin_run_pd3()
{
    printf("initialize pin\n--------------------\n");
    unsigned int reg = 0;
    unsigned int bit = pin_peek(reg, PD3);
    printf("register: %d\n", reg);
    print_binary(reg, PD3);
    printf("bit: %d\n\n", bit);

    printf("pin_on\n--------------------\n");
    reg = pin_on(reg, PD3);
    bit = pin_peek(reg, PD3);
    printf("register: %d\n", reg);
    print_binary(reg, PD3);
    printf("bit: %d\n\n", bit);

    printf("pin_off\n--------------------\n");
    reg = pin_off(reg, PD3);
    bit = pin_peek(reg, PD3);
    printf("register: %d\n", reg);
    print_binary(reg, PD3);
    printf("bit: %d\n\n", bit);

    printf("toggle_pin (ON)\n--------------------\n");
    reg = toggle_pin(reg, PD3);
    bit = pin_peek(reg, PD3);
    printf("register: %d\n", reg);
    print_binary(reg, PD3);
    printf("bit: %d\n\n", bit);

    printf("toggle_pin (OFF)\n--------------------\n");
    reg = toggle_pin(reg, PD3);
    bit = pin_peek(reg, PD3);
    printf("register: %d\n", reg);
    print_binary(reg, PD3);
    printf("bit: %d\n\n", bit);

    printf("rotate_left\n--------------------\n");
    reg = rotate_left(reg, 1);
    printf("register: %d\n", reg);
    print_binary(reg, PD3);
    printf("bit: %d\n\n", bit);

    printf("rotate_right\n--------------------\n");
    reg = rotate_right(reg, 1);
    printf("register: %d\n", reg);
    print_binary(reg, PD3);
    printf("bit: %d\n\n", bit);
}

void pin_run(int pin)
{
    printf("initialize pin\n--------------------\n");
    unsigned int reg = 0;
    unsigned int bit = pin_peek(reg, pin);
    printf("register: %d\n", reg);
    print_binary(reg, pin);
    printf("bit: %d\n\n", bit);

    printf("pin_on\n--------------------\n");
    reg = pin_on(reg, pin);
    bit = pin_peek(reg, pin);
    printf("register: %d\n", reg);
    print_binary(reg, pin);
    printf("bit: %d\n\n", bit);

    printf("pin_off\n--------------------\n");
    reg = pin_off(reg, pin);
    bit = pin_peek(reg, pin);
    printf("register: %d\n", reg);
    print_binary(reg, pin);
    printf("bit: %d\n\n", bit);

    printf("toggle_pin (ON)\n--------------------\n");
    reg = toggle_pin(reg, pin);
    bit = pin_peek(reg, pin);
    printf("register: %d\n", reg);
    print_binary(reg, pin);
    printf("bit: %d\n\n", bit);

    printf("toggle_pin (OFF)\n--------------------\n");
    reg = toggle_pin(reg, pin);
    bit = pin_peek(reg, pin);
    printf("register: %d\n", reg);
    print_binary(reg, pin);
    printf("bit: %d\n\n", bit);

    printf("rotate_left\n--------------------\n");
    reg = rotate_left(reg, 1);
    printf("register: %d\n", reg);
    print_binary(reg, pin);
    printf("bit: %d\n\n", bit);

    printf("rotate_right\n--------------------\n");
    reg = rotate_right(reg, 1);
    printf("register: %d\n", reg);
    print_binary(reg, pin);
    printf("bit: %d\n\n", bit);
}
