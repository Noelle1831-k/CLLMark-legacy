int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    int compareCount = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        compareCount++;
        if (arr[mid] == key) {
            break;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return compareCount;
}