int compare(const void *a, const void *b) {
    const int *tupleA = *(const int **)a;
    const int *tupleB = *(const int **)b;
    return tupleA[1] - tupleB[1];
}
void sortTuple(int tuples[][2], int n) {
    qsort(tuples, n, sizeof(tuples[0]), compare);
}