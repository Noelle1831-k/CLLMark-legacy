int leftInsertion(int* a, int n, int x) {
    int left = 0;
    int right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}