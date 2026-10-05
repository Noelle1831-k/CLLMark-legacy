void removeElements(int *list1, int size1, int *list2, int size2, int *result, int *resultSize) {
    int i, j, k = 0;
    for (i = 0; i < size1; ++i) {
        int found = 0;
        for (j = 0; j < size2; ++j) {
            if (list1[i] == list2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[k++] = list1[i];
        }
    }
    *resultSize = k;
}