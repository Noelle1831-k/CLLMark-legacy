int min_diff(int *arr, int size, int total, int index, int current, int needed) {
    if (needed == 0)
        return abs(total - 2 * current);
    if (index >= size || needed < 0)
        return total;
    int include = min_diff(arr, size, total, index + 1, current + arr[index], needed - 1);
    int exclude = min_diff(arr, size, total, index + 1, current, needed);
    return include < exclude ? include : exclude;
}
void can_divide(int *arr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    int half = n / 2;
    int minDifference = min_diff(arr, n, total, 0, 0, half);
    if (minDifference == total || !((n % 2 == 0 && half >= 3) || (n % 2 == 1 && half + 1 >= 3))) {
        printf("-1\n");
    } else {
        printf("%d\n", minDifference);
    }
}