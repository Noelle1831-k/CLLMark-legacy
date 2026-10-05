int findMinSwaps(int arr[], int n) {
    int left_count = 0, swaps = 0, max_ones_group = 0;
    int ones_count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            ones_count++;
        }
    }
    int current_window_ones = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            current_window_ones++;
        }
        if (i >= ones_count) {
            if (arr[i - ones_count] == 1) {
                current_window_ones--;
            }
        }
        if (current_window_ones > max_ones_group) {
            max_ones_group = current_window_ones;
        }
    }
    return ones_count - max_ones_group;
}