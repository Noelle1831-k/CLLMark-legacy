int maxSumIncreasingSubsequence(int arr[], int n) {
    int maxSum[n];
    for (int i = 0; i < n; i++) {
        maxSum[i] = arr[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && maxSum[i] < maxSum[j] + arr[i]) {
                maxSum[i] = maxSum[j] + arr[i];
            }
        }
    }
    int maxTotal = maxSum[0];
    for (int i = 1; i < n; i++) {
        if (maxTotal < maxSum[i]) {
            maxTotal = maxSum[i];
        }
    }
    return maxTotal;
}