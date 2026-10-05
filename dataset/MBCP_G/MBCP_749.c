int compareNumericStrings(const void *a, const void *b) {
    int num1 = atoi(*(const char **)a);
    int num2 = atoi(*(const char **)b);
    return (num1 - num2);
}
void sortNumericStrings(char **numsStr, int size) {
    qsort(numsStr, size, sizeof(char *), compareNumericStrings);
}