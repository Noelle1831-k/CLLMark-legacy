function oddBitSetNumber(n) {
    n |= n >> 1 & 0x55555555; // eslint-disable-line no-bitwise
    n |= n >> 2 & 0x33333333; // eslint-disable-line no-bitwise
    n |= n >> 4 & 0x0F0F0F0F; // eslint-disable-line no-bitwise
    n |= n >> 8 & 0x00FF00FF; // eslint-disable-line no-bitwise
    n |= n >> 16 & 0x0000FFFF; // eslint-disable-line no-bitwise
    return n & 0xFFFFFFFF;
}
