int toggleFAndLBits(int n) {
    int numberOfBits = sizeof(n) * 8;
    int firstBitMask = 1 << (numberOfBits - 1);
    int lastBitMask = 1;
    int toggleMask = firstBitMask | lastBitMask;
    return n ^ toggleMask;
}