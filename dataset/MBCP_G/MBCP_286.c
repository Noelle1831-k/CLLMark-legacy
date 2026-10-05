int maxSubArraySumRepeated(int *a, int n, int k) {
    int maxSum = a[0], curSum = a[0];
    for (int i = 1; i < n * k; i++) {
        curSum = (i < n) ? ((curSum > 0) ? curSum + a[i % n] : a[i % n]) : curSum + a[i % n];
        if (curSum > maxSum) {
            maxSum = curSum;
        }
    }
    if (k > 1) {
        int sumTotal = 0;
        for (int i = 0; i < n; i++) {
            sumTotal += a[i];
        }
        if (sumTotal > 0) {
            maxSum += (k - 2) * sumTotal;
        }
    }
    return maxSum;
}