int findMax(int arr[], int low, int high) {
    if (arr[low] <= arr[high]) {
        return arr[high];
    }
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1]) {
            return arr[mid];
        }
        if (arr[mid] >= arr[low]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return arr[low];
}