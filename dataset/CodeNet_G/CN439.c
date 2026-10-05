int maxSubarraySum(int n, int k, int *a) {
    int max_sum = 0;
    int current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += a[i];
    }
    max_sum = current_sum;
    for (int i = k; i < n; i++) {
        current_sum += a[i] - a[i - k];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    return max_sum;
}