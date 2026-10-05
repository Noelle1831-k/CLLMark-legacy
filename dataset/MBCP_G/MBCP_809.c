bool checkSmaller(int *testTup1, int *testTup2, int size) {
    for (int i = 0; i < size; i++) {
        if (testTup2[i] >= testTup1[i]) {
            return false;
        }
    }
    return true;
}