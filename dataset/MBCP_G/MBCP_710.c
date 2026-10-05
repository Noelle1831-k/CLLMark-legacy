void frontAndRear(int *testTup, int size, int *result) {
    if (size > 0) {
        result[0] = testTup[0];
        result[1] = testTup[size - 1];
    }
}