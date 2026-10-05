int frequencyOfLargest(int n, int arr[]) {
    int max_value = arr[0];
    int frequency = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == max_value) {
            frequency++;
        }
    }
    return frequency;
}