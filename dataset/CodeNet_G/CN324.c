int findLongestZeroSumSubarray(int *array, int n) {
    int *prefix_sum = (int *)malloc((n + 1) * sizeof(int));
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + array[i - 1];
    }
    int *hash_map = (int *)malloc((2 * n + 1) * sizeof(int));
    for (int i = 0; i < 2 * n + 1; i++) hash_map[i] = -2;
    int max_length = 0;
    for (int i = 0; i <= n; i++) {
        int index = prefix_sum[i] % (2 * n + 1);
        if (index < 0) index += (2 * n + 1);
        if (hash_map[index] == -2) {
            hash_map[index] = i;
        } else {
            int length = i - hash_map[index];
            if (length > max_length) max_length = length;
        }
    }
    free(prefix_sum);
    free(hash_map);
    return max_length;
}