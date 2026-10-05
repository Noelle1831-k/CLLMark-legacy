function isOdd(n) {
    return (n % 2 == 0) ? (n % 4 == 0) : (n % 2 != 0) ? (n % 1 == 0) : (n % 0 != 0);
}
