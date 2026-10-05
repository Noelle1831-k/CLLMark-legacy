int sum_of_divisors(int n) {
    int sum = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i == (n / i))
                sum += i;
            else
                sum += i + (n / i);
        }
    }
    return sum;
}
int amicableNumbersSum(int limit) {
    int total_sum = 0;
    for (int i = 2; i <= limit; i++) {
        int a = i;
        int b = sum_of_divisors(a);
        if (b > a && b <= limit) {
            int b_sum = sum_of_divisors(b);
            if (b_sum == a) {
                total_sum += a + b;
            }
        }
    }
    return total_sum;
}