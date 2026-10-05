void sort_and_count_operations(int arr[], int n, int *operation_count) {
    *operation_count = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            (*operation_count)++;
        }
    }
}