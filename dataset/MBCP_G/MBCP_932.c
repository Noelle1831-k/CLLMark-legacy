void removeDuplicateList(char (*list)[100], int *size) {
    int i, j, k;
    for (i = 0; i < *size; i++) {
        for (j = i + 1; j < *size; j++) {
            if (strcmp(list[i], list[j]) == 0) {
                for (k = j; k < *size - 1; k++) {
                    strcpy(list[k], list[k + 1]);
                }
                (*size)--;
                j--;
            }
        }
    }
}