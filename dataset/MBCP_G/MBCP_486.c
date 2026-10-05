double binomialProbability(int n, int k, double p) {
    double result = 1.0;
    for (int i = 0; i < k; i++) {
        result *= (n - i) / (double)(i + 1);
    }
    result *= pow(p, k) * pow(1 - p, n - k);
    return result;
}