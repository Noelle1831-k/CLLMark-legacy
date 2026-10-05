int lobbNum(int n, int m) {
    int catalan[n + 1];
    catalan[0] = 1;
    for (int i = 1; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }
    int lobb = ((2 * m + 1) * catalan[n + m]) / (m + n + 1);
    return lobb;
}