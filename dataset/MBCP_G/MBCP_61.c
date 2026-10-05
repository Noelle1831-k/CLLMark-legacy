int countSubstrings(const char *s, int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += s[j] - '0';
            if (sum == (j - i + 1)) {
                count++;
            }
        }
    }
    return count;
}