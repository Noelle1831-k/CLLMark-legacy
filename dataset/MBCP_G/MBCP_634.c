int evenPowerSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int evenNumber = 2 * i;
        sum += evenNumber * evenNumber * evenNumber * evenNumber;
    }
    return sum;
}