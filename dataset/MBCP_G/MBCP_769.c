int* diff(int* list1, int size1, int* list2, int size2, int* resultSize) {
    int* temp = (int*)malloc((size1 + size2) * sizeof(int));
    int k = 0, i, j;
    for (i = 0; i < size1; i++) {
        int found = 0;
        for (j = 0; j < size2; j++) {
            if (list1[i] == list2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) temp[k++] = list1[i];
    }
    for (i = 0; i < size2; i++) {
        int found = 0;
        for (j = 0; j < size1; j++) {
            if (list2[i] == list1[j]) {
                found = 1;
                break;
            }
        }
        if (!found) temp[k++] = list2[i];
    }
    *resultSize = k;
    return (int*)realloc(temp, k * sizeof(int));
}