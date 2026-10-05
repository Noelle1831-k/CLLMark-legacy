    int left = 0, right = a.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int value = a[mid];
        if (value < x) {
            left = mid + 1;
        } else if (value > x) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return left;
}