int compare_last_element(const void *a, const void *b) {
    const int *tuple1 = *(const int **)a;
    const int *tuple2 = *(const int **)b;
    return (tuple1[1] - tuple2[1]);
}
void sortListLast(int tuples[][2], int n) {
    qsort(tuples, n, sizeof(tuples[0]), compare_last_element);
}