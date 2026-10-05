int findSum(int arr[], int n) {
    int sum = 0;
    int frequency[1001] = {0};
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (frequency[arr[i]] == 1) {
            sum += arr[i];
        }
    }
    return sum;
}