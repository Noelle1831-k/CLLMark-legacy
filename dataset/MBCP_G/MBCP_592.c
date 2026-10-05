int sumOfProduct(int n) {
    int sum = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n - i; ++j) {
            int product = 1;
            for (int k = 1; k <= i; ++k) {
                product *= (n - k + 1);
                product /= k;
            }
            for (int k = 1; k <= j; ++k) {
                product *= (n - k - i + 1);
                product /= k;
            }
            sum += product;
        }
    }
    return sum;
}