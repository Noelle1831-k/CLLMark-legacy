int newmanPrime(int n) {
    if (n <= 0) return -1;
    long long int ns[n+1];
    ns[0] = 1;
    ns[1] = 1;
    for (int i = 2; i <= n; i++) {
        ns[i] = 2 * ns[i - 1] + ns[i - 2];
    }
    return ns[n];
}