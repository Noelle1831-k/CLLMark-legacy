void findDissimilar(int *tup1, int size1, int *tup2, int size2, int *result, int *resultSize) {
    int i, j, found;
    *resultSize = 0;
    for (i = 0; i < size1; i++) {
        found = 0;
        for (j = 0; j < size2; j++) {
            if (tup1[i] == tup2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[(*resultSize)++] = tup1[i];
        }
    }
    for (i = 0; i < size2; i++) {
        found = 0;
        for (j = 0; j < size1; j++) {
            if (tup2[i] == tup1[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[(*resultSize)++] = tup2[i];
        }
    }
}
