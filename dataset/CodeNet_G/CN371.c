int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void checkGiftPossibility(int N, int M, int T, int *a, int Q, int *A, int *B) {
    long long *possibleSums = (long long *)malloc((M + 1) * sizeof(long long));
    possibleSums[0] = 0;
    int currentCount = 1;
    for (int i = 0; i < N; i++) {
        for (int j = currentCount - 1; j >= 0; j--) {
            for (int k = 1; k <= M && j + k <= M; k++) {
                possibleSums[j + k] = possibleSums[j] + ((long long)a[i] * k);
            }
        }
        currentCount = (M + 1);
    }
    qsort(possibleSums, currentCount, sizeof(long long), compare);
    for (int q = 0; q < Q; q++) {
        int A_i = A[q];
        long long B_i = B[q];
        int isPossible = 0;
        for (int i = 0; i < currentCount; i++) {
            long long S = possibleSums[i];
            if ((S / T >= B_i) && (S % T >= A_i)) {
                isPossible = 1;
                break;
            }
        }
        if (isPossible) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    free(possibleSums);
}
