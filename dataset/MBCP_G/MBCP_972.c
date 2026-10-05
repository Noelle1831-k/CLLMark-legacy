void concatenateNested(int* result, int* tup1, int size1, int* tup2, int size2) {
    for (int i = 0; i < size1; i++) {
        result[i] = tup1[i];
    }
    for (int i = 0; i < size2; i++) {
        result[size1 + i] = tup2[i];
    }
}