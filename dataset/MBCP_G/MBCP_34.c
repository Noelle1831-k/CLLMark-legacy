int findMissing(int ar[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ar[mid] != mid + 1 && (mid == 0 || ar[mid - 1] == mid)) {
            return mid + 1;
        }
        if (ar[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}