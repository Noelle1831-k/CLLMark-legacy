int oddEquivalent(const char *s, int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[n - 1] == '1') {
            count++;
        }
        char last = s[n - 1];
        for (int j = n - 1; j > 0; --j) {
            s[j] = s[j - 1];
        }
        s[0] = last;
    }
    return count;
}
