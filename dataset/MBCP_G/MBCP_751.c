bool checkMinHeap(int arr[], int n, int i) {
    if (i >= (n - 1) / 2) {
        return true;
    }
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    bool isLeftMin = left < n ? arr[i] <= arr[left] : true;
    bool isRightMin = right < n ? arr[i] <= arr[right] : true;
    if (isLeftMin && isRightMin) {
        return checkMinHeap(arr, n, left) && checkMinHeap(arr, n, right);
    }
    return false;
}