int setLeftMostUnsetBit(int n) {
    int mask = 1 << (sizeof(int) * 8 - 1);
    while (mask != 0 && (n & mask) != 0) {
        mask >>= 1;
    }
    return n | mask;
}