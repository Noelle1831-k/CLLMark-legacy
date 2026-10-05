int oddNumSum(int n) {
    int sum = 0;
    int odd = 1;
    for (int i = 0; i < n; i++) {
        sum += odd * odd * odd * odd;
        odd += 2;
    }
    return sum;
}