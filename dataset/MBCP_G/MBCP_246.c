double babylonianSquareroot(int number) {
    double x = number;
    double y = 1.0;
    double e = 0.000001;
    while (x - y > e) {
        x = (x + y) / 2;
        y = number / x;
    }
    return x;
}