void similarElements(int *testTup1, int size1, int *testTup2, int size2, int *result, int *resultSize) {
    int i, j, k = 0;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            if (testTup1[i] == testTup2[j]) {
                int isDuplicate = 0;
                for (int x = 0; x < k; x++) {
                    if (result[x] == testTup1[i]) {
                        isDuplicate = 1;
                        break;
                    }
                }
                if (!isDuplicate) {
                    result[k++] = testTup1[i];
                }
            }
        }
    }
    *resultSize = k;
}