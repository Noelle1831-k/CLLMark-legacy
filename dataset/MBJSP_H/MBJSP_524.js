function maxSumIncreasingSubsequence(arr, n) {
    let maxSum = 0;
    const dp = Array(n).fill(0);

    for (let i = 0; i < n; i++) {
        dp[i] = arr[i];
    }

    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }
    }

    for (let i = 0; i < n; i++) {
        maxSum = Math.max(maxSum, dp[i]);
    }

    return maxSum;
}
