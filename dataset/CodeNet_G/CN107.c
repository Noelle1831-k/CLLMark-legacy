void estimate_cheese(int A, int B, int C, int n, int *R) {
    double diagonal = sqrt((double)A * A + (double)B * B + (double)C * C) / 2.0;
    for (int i = 0; i < n; ++i) {
        if (R[i] >= diagonal) {
            printf("OK\n");
        } else {
            printf("NA\n");
        }
    }
}
