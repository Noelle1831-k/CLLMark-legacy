int hammingDistance(int x, int y) {
    int xorVal = x ^ y, count = 0;
    while (xorVal) {
        count += xorVal & 1;
        xorVal >>= 1;
    }
    return count;
}
int totalHammingDistance(int n) {
    int totalDist = 0;
    for (int i = 0; i < n; ++i) {
        totalDist += hammingDistance(i, i + 1);
    }
    return totalDist;
}