int isSubArray(int a[], int b[], int n, int m) {
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (a[i + j] != b[j]) {
                break;
            }
        }
        if (j == m) {
            return 1;
        }
    }
    return 0;
}