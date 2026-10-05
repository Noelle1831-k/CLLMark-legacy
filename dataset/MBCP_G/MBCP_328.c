void rotateLeft(int arr[], int size, int m, int n, int result[]) {
    int index = 0;
    m = m % size;
    for (int i = m; i < size; i++) {
        result[index++] = arr[i];
    }
    for (int i = 0; i < m; i++) {
        result[index++] = arr[i];
    }
    if (index < n) {
        int loop_count = n / index;
        int remain = n % index;
        for (int i = 0; i < loop_count; i++) {
            for (int j = 0; j < index; j++) {
                result[index * (i + 1) + j] = result[j];
            }
        }
        for (int i = 0; i < remain; i++) {
            result[index * loop_count + i] = result[i];
        }
    }
}