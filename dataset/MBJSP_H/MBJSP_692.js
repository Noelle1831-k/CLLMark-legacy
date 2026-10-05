function lastTwoDigits(n) {
    let fact = 1;
    while (n > 1) {
        fact *= n;
        n -= 1;
    }
    return fact % 100;
}
