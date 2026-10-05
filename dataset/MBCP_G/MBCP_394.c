bool checkDistinct(int *testTup, size_t size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (testTup[i] == testTup[j]) {
                return false;
            }
        }
    }
    return true;
}