int maxProduct(int arr[], int n) {
    int *maxProductArr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        maxProductArr[i] = arr[i];
    }
    int maxProductValue = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && maxProductArr[i] < maxProductArr[j] * arr[i]) {
                maxProductArr[i] = maxProductArr[j] * arr[i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (maxProductValue < maxProductArr[i]) {
            maxProductValue = maxProductArr[i];
        }
    }
    return maxProductValue;
}