int findExtra(int arr1[], int arr2[], int n) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr1[mid] == arr2[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}