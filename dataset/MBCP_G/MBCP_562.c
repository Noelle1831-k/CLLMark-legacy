int findMaxLength(int **lst, int lstSize, int *subListSizes) {
    int maxLength = 0;
    for (int i = 0; i < lstSize; ++i) {
        if (subListSizes[i] > maxLength) {
            maxLength = subListSizes[i];
        }
    }
    return maxLength;
}