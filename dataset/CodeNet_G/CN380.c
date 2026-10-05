int is_sorted(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}
int bozosort(int n, int *arr, int q, int *swaps) {
    if (is_sorted(arr, n)) return 0;
    for (int i = 0; i < q; ++i) {
        int x = swaps[2 * i] - 1;
        int y = swaps[2 * i + 1] - 1;
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
        if (is_sorted(arr, n)) return i + 1;
    }
    return -1;
}