int sum(int n) {
    int sum = 0;
    int i;
    for (i = 2; n > 1; i++) {
        if (n % i == 0) {
            sum += i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    return sum;
}