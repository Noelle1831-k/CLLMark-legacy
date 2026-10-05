int rightInsertion(int a[], int size, int x) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}