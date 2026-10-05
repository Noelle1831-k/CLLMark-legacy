void pairWise(int* arr, int size, int result[][2]) {
    for (int i = 0; i < size - 1; i++) {
        result[i][0] = arr[i];
        result[i][1] = arr[i + 1];
    }
}