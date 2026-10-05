void evaluate_snacks(int n, int snacks[][4], int P, int Q, int R, int C) {
    int found = 0;    
    for (int i = 0; i < n; ++i) {
        int p = snacks[i][1];
        int q = snacks[i][2];
        int r = snacks[i][3];
        int calories = 4 * p + 9 * q + 4 * r;
        if (p <= P && q <= Q && r <= R && calories <= C) {
            printf("%d ", snacks[i][0]);
            found = 1;
        }
    }
    if (!found) {
        printf("NA");
    }
    printf("\n");
}
