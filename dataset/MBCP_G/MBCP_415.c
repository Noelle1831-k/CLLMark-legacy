void maxProduct(int arr[], int n, int *x, int *y) {
    if (n < 2) return;
    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2) {
            min2 = arr[i];
        }
    }
    if (max1 * max2 > min1 * min2) {
        *x = max2;
        *y = max1;
    } else {
        *x = min1;
        *y = min2;
    }
}