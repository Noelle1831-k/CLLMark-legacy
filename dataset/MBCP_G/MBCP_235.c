int evenBitSetNumber(int n) {
    for (int i = 0; i < sizeof(int) * 8; i += 2) {
        n |= (1 << i);
    }
    return n;
}