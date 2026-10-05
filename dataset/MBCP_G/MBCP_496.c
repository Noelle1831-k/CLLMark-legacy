void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}
void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}
void heapQueueSmallest(int nums[], int size, int n, int result[]) {
    buildHeap(nums, size);
    for (int i = 0; i < n; i++) {
        result[i] = nums[0];
        nums[0] = nums[size - 1];
        size--;
        heapify(nums, size, 0);
    }
}