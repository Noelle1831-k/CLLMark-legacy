int* moveFirst(int* testList, int size) {
    if (size <= 1) return testList;
    int lastElement = testList[size - 1];
    for (int i = size - 1; i > 0; i--) {
        testList[i] = testList[i - 1];
    }
    testList[0] = lastElement;
    return testList;
}