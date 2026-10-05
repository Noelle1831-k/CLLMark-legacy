function maxPrimeFactors(n) {
    if (n == 0) {
        return 0;
    }
    var max = 2;
    for (var i = 3; i < n; i++) {
        if (n % i == 0 && max < i) {
            max = i;
        }
    }
    return max;
}
