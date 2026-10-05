int pairOrSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += arr[i] ^ arr[j];
        }
    }
    return sum;
}