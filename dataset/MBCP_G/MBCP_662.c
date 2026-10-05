typedef struct {
    char key[50];
    int *values;
    int size;
} dict_t;
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void sortedDict(dict_t *dicts, int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        qsort(dicts[i].values, dicts[i].size, sizeof(int), compare);
    }
}