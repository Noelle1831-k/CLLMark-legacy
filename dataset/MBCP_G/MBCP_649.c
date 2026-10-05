int sumRangeList(int nums[], int size, int m, int n) {
    int sum = 0;
    for (int i = m; i <= n && i < size; i++) {
        sum += nums[i];
    }
    return sum;
}