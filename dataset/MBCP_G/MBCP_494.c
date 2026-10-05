int binaryToInteger(int testTup[], int size) {
    int decimalValue = 0;
    for (int i = 0; i < size; i++) {
        decimalValue += testTup[i] * pow(2, size - i - 1);
    }
    return decimalValue;
}