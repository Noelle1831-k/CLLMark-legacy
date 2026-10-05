unsigned int toggleMiddleBits(unsigned int n) {
    int numBits = sizeof(n) * 8;
    if (numBits <= 2) return n;
    unsigned int mask = ((1U << (numBits - 1)) - 1) & ~1U;
    return n ^ mask;
}