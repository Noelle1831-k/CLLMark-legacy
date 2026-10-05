int sumDifference(int n) {
    int sum = 0;
    int sumOfSquares = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
        sumOfSquares += i * i;
    }
    int squareOfSum = sum * sum;
    return squareOfSum - sumOfSquares;
}