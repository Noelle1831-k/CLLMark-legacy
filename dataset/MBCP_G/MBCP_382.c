int findRotationCount(int a[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        if (a[low] <= a[high]) {
            return low;
        }
        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if (a[mid] <= a[next] && a[mid] <= a[prev]) {
            return mid;
        } else if (a[mid] <= a[high]) {
            high = mid - 1;
        } else if (a[mid] >= a[low]) {
            low = mid + 1;
        }
    }
    return 0;
}
