double multiplyNum(int numbers[], int length) {
    if (length == 0) return 0.0;
    double product = 1.0;
    for (int i = 0; i < length; i++) {
        product *= numbers[i];
    }
    return product / length;
}