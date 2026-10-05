int countRotation(int arr[], int n) {
    int minVal = arr[0];
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}