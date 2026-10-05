void quicksort(char *array[], int low, int high) {
    if (high > low) {
        int pivot = partition(array, low, high);
        quicksort(array, low, pivot - 1);
        quicksort(array, pivot + 1, high);
    }
}