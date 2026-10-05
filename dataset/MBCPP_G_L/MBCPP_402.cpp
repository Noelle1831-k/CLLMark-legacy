if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    r = min(r, n - r);
    vector<int> C(r + 1, 0);
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--) {
            C[j] = (C[j] + C[j - 1]) % p;
        }
    }
    return C[r];
}