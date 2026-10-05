int compare(const void *a, const void *b) {
    float v1 = atof(((const char **)a)[1]);
    float v2 = atof(((const char **)b)[1]);
    if (v1 < v2) return 1;
    if (v1 > v2) return -1;
    return 0;
}
void floatSort(char *price[][2], int n) {
    qsort(price, n, sizeof(price[0]), compare);
}