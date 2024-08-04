#include "bit.h"

unsigned int rotate_left(unsigned int value, int count)
{
    const unsigned int mask = (__CHAR_BIT__ * sizeof(value)) - 1;
    count &= mask;
    return (value << count) | (value >> (-count & mask));
}

unsigned int rotate_right(unsigned int value, int count)
{
    const unsigned int mask = (__CHAR_BIT__ * sizeof(value)) - 1;
    count &= mask;
    return (value >> count) | (value << (-count & mask));
}

unsigned int swap_endian(unsigned int x)
{
    return (x >> 24) | ((x << 8) & 0x00FF0000) | ((x >> 8) & 0x0000FF00) | (x << 24);
}