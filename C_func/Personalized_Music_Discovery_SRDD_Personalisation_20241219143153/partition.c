int partition(char *array[], int low, int high) {
    char *pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (strcmp(array[j], pivot) < 0) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
}