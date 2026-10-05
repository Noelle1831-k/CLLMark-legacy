int* flattenList(int list1[][3], int list1Size[], int list1Count, int *returnSize) {
    int totalSize = 0;
    for(int i = 0; i < list1Count; ++i) {
        totalSize += list1Size[i];
    }
    int *result = (int*)malloc(totalSize * sizeof(int));
    int k = 0;
    for(int i = 0; i < list1Count; ++i) {
        for(int j = 0; j < list1Size[i]; ++j) {
            result[k++] = list1[i][j];
        }
    }
    *returnSize = totalSize;
    return result;
}