int findFirstOccurrence(int *a, int size, int x) {
    int low = 0, high = size - 1;
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == x) {
            result = mid;
            high = mid - 1;
        } else if (a[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}