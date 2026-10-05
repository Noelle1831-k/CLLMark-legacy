    int divisors = 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            divisors = divisors + 1;
        }
    }
    return (divisors % 2 == 0) ? "Even" : "Odd";
}