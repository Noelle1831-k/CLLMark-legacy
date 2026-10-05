int maxSubarrayProduct(int arr[], int n) {
    int max_ending_here = 1, min_ending_here = 1, max_so_far = 0, i;
    for (i = 0; i < n; i++) {
        if (arr[i] > 0) {
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = (min_ending_here * arr[i] < 1) ? min_ending_here * arr[i] : 1;
        } else if (arr[i] == 0) {
            max_ending_here = 1;
            min_ending_here = 1;
        } else {
            int temp = max_ending_here;
            max_ending_here = (min_ending_here * arr[i] > 1) ? min_ending_here * arr[i] : 1;
            min_ending_here = temp * arr[i];
        }
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
    }
    return max_so_far;
}