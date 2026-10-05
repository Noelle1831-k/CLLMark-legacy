bool checkEvenParity(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count % 2 == 0;
}