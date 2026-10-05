int compare(const void *a, const void *b) {
    int *rowA = *(int **)a;
    int *rowB = *(int **)b;
    int sumA = 0, sumB = 0;
    for (int i = 0; rowA[i] != '\0'; i++) {
        sumA += rowA[i];
    }
    for (int i = 0; rowB[i] != '\0'; i++) {
        sumB += rowB[i];
    }
    return sumA - sumB;
}
void sortMatrix(int **matrix, int rows, int cols) {
    qsort(matrix, rows, sizeof(int *), compare);
}