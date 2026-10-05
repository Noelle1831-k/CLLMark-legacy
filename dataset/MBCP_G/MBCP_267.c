int squareSum(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int oddNum = 2 * i + 1;
        sum += oddNum * oddNum;
    }
    return sum;
}