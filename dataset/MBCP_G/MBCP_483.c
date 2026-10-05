int firstFactorialDivisibleNumber(int x) {
    int n = 1;
    int factorial = 1;
    while (factorial % x != 0) {
        n++;
        factorial *= n;
    }
    return n;
}