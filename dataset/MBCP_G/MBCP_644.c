void reverseArrayUptoK(int *arr, int n, int k) {
    int start = 0, end = k - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}