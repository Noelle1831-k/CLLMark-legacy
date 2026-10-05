int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int sum_of_common_divisors(int a, int b) {
    int g = gcd(a, b);
    int sum = 0;
    for (int i = 1; i <= g; i++) {
        if (g % i == 0) {
            sum += i;
        }
    }
    return sum;
}