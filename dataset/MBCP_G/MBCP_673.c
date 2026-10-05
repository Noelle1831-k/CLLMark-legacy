int convert(int *list, int size) {
    int result = 0;
    for(int i = 0; i < size; i++) {
        result = result * 10 + list[i];
    }
    return result;
}