void countDuplic(int* lists, int size, int** result, int* resSizes) {
    int current = lists[0];
    int currentCount = 1;
    int idx = 0;
    resSizes[0] = 0;
    resSizes[1] = 0;
    for (int i = 1; i < size; i++) {
        if (lists[i] == current) {
            currentCount++;
        } else {
            result[0][resSizes[0]++] = current;
            result[1][resSizes[1]++] = currentCount;
            current = lists[i];
            currentCount = 1;
        }
    }
    result[0][resSizes[0]++] = current;
    result[1][resSizes[1]++] = currentCount;
}