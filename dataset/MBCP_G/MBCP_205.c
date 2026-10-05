void inversionElements(int *testTup, int size, int *result) {
    int i;
    for (i = 0; i < size; i++) {
        result[i] = -(testTup[i] + 1);
    }
}