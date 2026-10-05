int oddNumSum(int n) {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        int odd = 2 * i + 1;
        sum += odd * odd * odd * odd * odd;
    }
    return sum;
}