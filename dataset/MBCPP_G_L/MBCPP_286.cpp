if(n == 0 || k <= 0) return 0;
int maxSum = INT_MIN, currentSum = 0;
for(int i = 0; i < n * min(k, 2); i++) {
    currentSum += a[i % n];
    maxSum = max(maxSum, currentSum);
    if(currentSum < 0) currentSum = 0;
}
if(k > 2) {
    int prefixSum = 0, suffixSum = 0, totalSum = accumulate(a.begin(), a.end(), 0);
    int maxPrefixSum = INT_MIN, maxSuffixSum = INT_MIN;
    for(int i = 0; i < n; i++) {
        prefixSum += a[i];
        maxPrefixSum = max(maxPrefixSum, prefixSum);
    }
    for(int i = n - 1; i >= 0; i--) {
        suffixSum += a[i];
        maxSuffixSum = max(maxSuffixSum, suffixSum);
    }
    maxSum = max(maxSum, maxSuffixSum + maxPrefixSum + max(0, totalSum) * (k - 2));
}
return maxSum;
}