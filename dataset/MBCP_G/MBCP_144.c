int sumPairs(int arr[], int n) {
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            total_sum += abs(arr[i] - arr[j]);
        }
    }
    return total_sum;
}