void addLists(int* testList, int listSize, int* testTup, int tupSize, int* result) {
    int i, j;
    for (i = 0; i < tupSize; i++) {
        result[i] = testTup[i];
    }
    for (j = 0; j < listSize; j++, i++) {
        result[i] = testList[j];
    }
}