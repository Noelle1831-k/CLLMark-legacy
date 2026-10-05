int evenBinomialCoeffSum(int n) {
    int sum = 0;
    int coeff = 1;
    for (int k = 0; k <= n; k += 2) {
        if (k > 0)
            coeff = coeff * (n - k + 1) / k;
        sum += coeff;
    }
    return sum;
}