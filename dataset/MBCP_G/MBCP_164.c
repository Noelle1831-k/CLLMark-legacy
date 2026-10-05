int sum_of_divisors(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}
int areequivalent(int num1, int num2) {
    int sum1 = sum_of_divisors(num1);
    int sum2 = sum_of_divisors(num2);
    return sum1 == sum2;
}