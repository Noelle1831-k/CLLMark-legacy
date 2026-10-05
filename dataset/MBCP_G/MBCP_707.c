int countSetBits(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int num = i;
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
    }
    return count;
}