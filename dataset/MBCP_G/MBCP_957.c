int getFirstSetBitPos(int n) {
    if (n == 0) return 0;
    int position = 1;
    while (!(n & 1)) {
        n >>= 1;
        position++;
    }
    return position;
}