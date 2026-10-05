double calculateAverage(int *array, int size) {
    if (array == NULL || size <= 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}