int sumElements(int *testTup, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += testTup[i];
    }
    return sum;
}