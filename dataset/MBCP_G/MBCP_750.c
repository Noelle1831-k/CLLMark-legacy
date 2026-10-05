void addTuple(int *testList, int listSize, int *testTup, int tupSize, int *result) {
    int i;
    for (i = 0; i < listSize; i++) {
        result[i] = testList[i];
    }
    for (int j = 0; j < tupSize; j++) {
        result[i + j] = testTup[j];
    }
}