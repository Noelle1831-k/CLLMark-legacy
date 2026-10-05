int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void smallNnum(int list[], int size, int n, int result[]) {
    qsort(list, size, sizeof(int), cmpfunc);
    for (int i = 0; i < n; i++) {
        result[i] = list[i];
    }
}