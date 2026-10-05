int breaksum(int n) {
    if (n == 0)
        return 0;
    int sum = n / 2 + n / 3 + n / 4;
    if (sum > n)
        return breaksum(n / 2) + breaksum(n / 3) + breaksum(n / 4);
    else
        return n;
}