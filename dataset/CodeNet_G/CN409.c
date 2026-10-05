int findShortestRepeat(char *s, int n) {
    for (int len = 1; len <= n; ++len) {
        if (n % len == 0) {
            int repeat = 1;
            for (int j = len; j < n; ++j) {
                if (s[j] != s[j % len]) {
                    repeat = 0;
                    break;
                }
            }
            if (repeat) {
                return len;
            }
        }
    }
    return n;
}
void processString(int n, int q, char *s, int *p, char *c) {
    for (int i = 0; i < q; ++i) {
        s[p[i] - 1] = c[i];
        int result = findShortestRepeat(s, n);
        printf("%d\n", result);
    }
}