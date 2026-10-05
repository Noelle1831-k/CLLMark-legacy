int maxSubarraySum(int arr[], int n) {
    int maxSum = arr[0];
    int currentSum = arr[0];
    for (int i = 1; i < n; i++) {
        currentSum = currentSum > 0 ? currentSum + arr[i] : arr[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    return maxSum;
}