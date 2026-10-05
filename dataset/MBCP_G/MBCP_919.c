int multiplyList(int *items, int size) {
    int result = 1;
    for (int i = 0; i < size; i++) {
        result *= items[i];
    }
    return result;
}