double medianNumbers(int a, int b, int c) {
    if ((a > b && a < c) || (a < b && a > c)) {
        return (double)a;
    } else if ((b > a && b < c) || (b < a && b > c)) {
        return (double)b;
    } else {
        return (double)c;
    }
}