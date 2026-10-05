int smallestDivisor(int n) {
    if (n <= 1) return n;
    if (n % 2 == 0) return 2;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return i;
    }
    return n;
}