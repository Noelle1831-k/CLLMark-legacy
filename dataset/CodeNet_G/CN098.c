int maxSumSequence(int n, int matrix[100][100]) {
    int maxSum = INT_MIN;
    for (int left = 0; left < n; left++) {
        int temp[100] = {0};
        for (int right = left; right < n; right++) {
            for (int i = 0; i < n; i++) {
                temp[i] += matrix[i][right];
            }
            int currentSum = 0;
            int maxTempSum = INT_MIN;
            for (int i = 0; i < n; i++) {
                currentSum += temp[i];
                if (currentSum > maxTempSum) {
                    maxTempSum = currentSum;
                }
                if (currentSum < 0) {
                    currentSum = 0;
                }
            }
            if (maxTempSum > maxSum) {
                maxSum = maxTempSum;
            }
        }
    }
    return maxSum;
}