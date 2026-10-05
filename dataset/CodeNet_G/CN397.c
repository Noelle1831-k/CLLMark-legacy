int cmp(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}
void findKthLargestXor(int N, int K, int* a) {
    int *xorValues = (int*)malloc((N * (N + 1) / 2) * sizeof(int));
    int index = 0;
    for (int L = 0; L < N; L++) {
        int xor_sum = 0;
        for (int R = L; R < N; R++) {
            xor_sum ^= a[R];
            xorValues[index++] = xor_sum;
        }
    }
    qsort(xorValues, index, sizeof(int), cmp);
    printf("%d\n", xorValues[K - 1]);
    free(xorValues);
}
