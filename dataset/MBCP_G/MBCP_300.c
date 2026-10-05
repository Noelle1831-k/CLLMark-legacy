double countBinarySeq(int n) {
    double result = 1.0;
    for (int i = 0; i < n; i++) {
        result *= (n + i + 1) / (double)(i + 1);
    }
    return result;
}