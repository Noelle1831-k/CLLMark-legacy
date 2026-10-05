int findDivisor(int x, int y) {
    int maxDivisor = 0;
    int maxCount = 0;
    for (int i = 1; i <= y; ++i) {
        int count = 0;
        for (int j = x; j <= y; ++j) {
            if (j % i == 0) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxDivisor = i;
        }
    }
    return maxDivisor;
}