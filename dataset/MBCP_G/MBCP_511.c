int findMinSum(int num) {
    int sum = INT_MAX;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            int factorSum = i + (num / i);
            if (factorSum < sum) {
                sum = factorSum;
            }
        }
    }
    return sum;
}