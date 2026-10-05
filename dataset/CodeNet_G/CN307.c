int solve(int M, int N, int *w, int *t, int *c, int *b) {
    int left = 0, right = M + 1, mid;
    while (right - left > 1) {
        mid = (left + right) / 2;
        int used[N];
        for (int i = 0; i < N; ++i) used[i] = 0;
        int possible = 1;
        for (int i = 0; i < mid && possible; ++i) {
            possible = 0;
            for (int j = 0; j < N; ++j) {
                if (used[j] + w[i] <= c[j] && used[j] + t[i] <= b[j]) {
                    used[j] += w[i];
                    possible = 1;
                    break;
                }
            }
        }
        if (possible) left = mid;
        else right = mid;
    }
    return left;
}