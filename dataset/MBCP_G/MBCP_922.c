void maxProduct(int arr[], int n, int result[2]) {
    if (n < 2) return;
    int max1 = arr[0] > arr[1] ? arr[0] : arr[1];
    int max2 = arr[0] < arr[1] ? arr[0] : arr[1];
    int min1 = arr[0] < arr[1] ? arr[0] : arr[1];
    int min2 = arr[0] > arr[1] ? arr[0] : arr[1];
    for (int i = 2; i < n; i++) {
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
        result[0] = max1;
        result[1] = max2;
    } else {
        result[0] = min1;
        result[1] = min2;
    }
}