int cubeSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int even_number = 2 * i;
        sum += even_number * even_number * even_number;
    }
    return sum;
}