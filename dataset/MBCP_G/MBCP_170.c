int sumRangeList(int *list1, int size, int m, int n) {
    int sum = 0;
    for(int i = m; i <= n && i < size; i++) {
        sum += list1[i];
    }
    return sum;
}