bool testDuplicate(int *arraynums, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arraynums[i] == arraynums[j]) {
                return true;
            }
        }
    }
    return false;
}