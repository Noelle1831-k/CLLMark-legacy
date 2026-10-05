int maxSum(int* arr, int n) {
    int inc[n];
    int dec[n];
    int i, j;
    for (i = 0; i < n; i++) {
        inc[i] = arr[i];
    }
    for (i = n - 1; i >= 0; i--) {
        dec[i] = arr[i];
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && inc[i] < inc[j] + arr[i]) {
                inc[i] = inc[j] + arr[i];
            }
        }
    }
    for (i = n - 2; i >= 0; i--) {
        for (j = n - 1; j > i; j--) {
            if (arr[i] > arr[j] && dec[i] < dec[j] + arr[i]) {
                dec[i] = dec[j] + arr[i];
            }
        }
    }
    int max_sum = inc[0] + dec[0] - arr[0];
    for (i = 1; i < n; i++) {
        if (inc[i] + dec[i] - arr[i] > max_sum) {
            max_sum = inc[i] + dec[i] - arr[i];
        }
    }
    return max_sum;
}