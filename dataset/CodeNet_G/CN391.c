int isRelevant(int W, int H, int* a, int* b) {
    int i, j;
    int rowSum = 0, colSum = 0;
    for (i = 0; i < W; i++) {
        rowSum += a[i];
    }
    for (j = 0; j < H; j++) {
        colSum += b[j];
    }
    return rowSum == colSum ? 1 : 0;
}