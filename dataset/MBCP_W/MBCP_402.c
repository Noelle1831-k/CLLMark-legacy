int ncrModp(int n, int r, int p) {
    if (r > n) 
        return 0;
    if (r == 0 || r == n)
        return 1;
    int *C = (int *)malloc(sizeof(int) * r + 1);
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = (i < r ? i : r); j > 0; j--) {
            C[j] = (C[j] + C[j - 1]) % p;
        }
    }
    return C[r];
}