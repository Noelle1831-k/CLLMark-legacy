int maxAbsDiff(int arr[], int n) {
    int max_diff = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int diff = arr[i] - arr[j];
            if (diff < 0) diff = -diff;
            if (diff > max_diff) max_diff = diff;
        }
    }
    return max_diff;
}