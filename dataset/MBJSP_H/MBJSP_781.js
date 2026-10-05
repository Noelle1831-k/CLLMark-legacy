function countDivisors(n) {
    var divisors = [], divisorsCount = 0;

    for (var i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisors[divisorsCount++] = i;
        }
    }

    if (divisorsCount % 2 == 0) {
        return "Even";
    } else {
        return "Odd";
    }
}
