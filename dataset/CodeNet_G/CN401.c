int largestPowerOfTwo(int N) {
    int power = 1;
    while (power <= N) {
        power <<= 1;
    }
    return power >> 1;
}