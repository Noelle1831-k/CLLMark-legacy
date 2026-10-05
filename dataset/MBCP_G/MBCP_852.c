void removeNegs(int *numList, int size, int *result, int *resultSize) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (numList[i] >= 0) {
            result[j++] = numList[i];
        }
    }
    *resultSize = j;
}