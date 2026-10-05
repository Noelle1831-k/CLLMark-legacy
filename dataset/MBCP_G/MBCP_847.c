int* lcopy(int* xs, int size) {
    int* copy = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        copy[i] = xs[i];
    }
    return copy;
}