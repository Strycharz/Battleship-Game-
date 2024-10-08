#include "Bitmask.h"

Bitmask::Bitmask() : bits(0) { }

void Bitmask::setMask(Bitmask& other)
{
    bits = other.getMask();
}

uint32_t Bitmask::getMask() const
{
    return bits;
}

bool Bitmask::getBit(int pos) const
{
    return (bits & (1 << pos)) != 0;
}

void Bitmask::setBit(int pos, bool on)
{
    if(on)
    {
        setBit(pos);
    }
    else
    {
        clearBit(pos);
    }
}

void Bitmask::setBit(int pos)
{
    bits = bits | 1 << pos;
}

void Bitmask::clearBit(int pos)
{
    bits = bits & ~(1 << pos);
}

void Bitmask::clear()
{
    bits = 0;
}