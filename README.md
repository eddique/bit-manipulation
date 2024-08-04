# bit-manipulation

An excercise in bit manipulation through masking and rotation. Bit manipulation involves direct or indirect modification of bits in binary data. This can be done using bitwise operators, which are used to perform bit-level operations on binary numbers.

## Quick Start

```sh
git clone https://github.com/eddique/bit-manipulation.git
cd bit-manipulation
argo run
```

## Usage

With the [argo](https://github.com/eddique/argo) build tool CLI

```sh
# argo run <PIN_NUMBER?>
argo run 4

argo run
```

```sh
running pin: PD3
initialize pin
--------------------
register: 0
binary register: 00000000
bit: 0

pin_off
--------------------
register: 0
binary register: 00000000
bit: 0

pin_on
--------------------
register: 4
binary register: 00000100
bit: 1

toggle_pin (ON)
--------------------
register: 0
binary register: 00000000
bit: 0

toggle_pin (OFF)
--------------------
register: 4
binary register: 00000100
bit: 1

rotate_left
--------------------
register: 8
binary register: 00001000
bit: 1

rotate_right
--------------------
register: 4
binary register: 00000100
bit: 1
```

## Bit Manipulation

### AND

The AND operator (&) compares each bit of the first operand to the corresponding bit of the second operand. If both bits are 1, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0.

```c
int reg = 0; // 00000000
int pin = 3;
// 1 00000001
// 1 << 3 00001000
// ~(1 << 3) 11110111
// reg & (1 << 3) 00000000
reg &= ~(1 << pin);
```

### OR

The OR operator (|) compares each bit of the first operand to the corresponding bit of the second operand. If either bit is 1, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0.

```c
int reg = 0; // 00000000
int pin = 3;
// 1 00000001
// 1 << 3 00001000
// reg | (1 << 3) 00001000
reg |= (1 << pin);
```

### XOR

The XOR operator (^) compares each bit of the first operand to the corresponding bit of the second operand. If the bits are both 1 or both 0, the corresponding result bit is set to 0. Otherwise, the corresponding result bit is set to 1.

```c
int reg = 0; // 00000000
int pin = 3;
// 1 00000001
// 1 << 3 00001000
// reg ^ (1 << 3) 00001000
reg ^= (1 << pin);

// reg 00001000
// 1 << 3 00001000
// reg ^ (1 << 3) 00000000
reg ^=(1 << pin);
```

### Peek

Peeking is the process of looking at a specific bit in a binary number without changing the number itself. This can be done using the bitwise AND operator and a mask that has a 1 in the position of the bit we want to peek at.

```c
int reg = 0; // 00000000
int pin = 3;
// 1 00000001
// 1 << 3 00001000
// reg & (1 << 3) 00000000; if bit is on in register 1, off 0
// (reg & (1 << 3)) >> 3 000000000; move position 3 to the right 3; if on the result is 1, off 0
int bit = (reg & (1 << pin)) >> pin;
```

### Reversal

Reversal is the process of flipping the order of bits in a binary number. This can be done by iterating over the bits in one order and writing them to a new number in the opposite order.

```c
size_t register_slots = 8;
unsigned int le_byte[register_slots];
for (int i = 0; i < register_slots; i++)
{
    int bit = (reg & (1 << i)) >> i;
    le_byte[i] = bit;
}

unsigned int be_byte[register_slots];
for (int i = register_slots - 1; i >= 0; i--)
{
    int bit = (reg & (1 << i)) >> i;
    be_byte[i] = bit;
}
```

### Endianness

Endianness is the order or sequence of bytes of a word of digital data. Most significant byte first (big-endian) or least significant byte first (little-endian) are the two choices.

```c
#include <stdio.h>
unsigned int swap_endian(unsigned int x)
{
    // x >> 24; move bits 24 places right, puts leftmost byte in rightmost position
    // ((x << 8) & 0x00FF0000); move bits 8 places left masks out all but the second byte from the left
    // ((x >> 8) & 0x0000FF00); move the bits 8 places to the right, masks out all but the second byte from the right.
    // (x << 24)  move bits 24 places right, puts rightmost byte in leftmost position
    return (x >>24) | ((x << 8) & 0x00FF0000) | ((x >> 8) & 0x0000FF00) | (x << 24);
}
unsigned int le_value = 0x12345678; // A 32-bit integer in little endian
unsigned int be_value = swap_endian(le_value); // Convert to big endian
printf("Little Endian: 0x%08x\n", le_value);
printf("Big Endian: 0x%08x\n", be_value);
```
