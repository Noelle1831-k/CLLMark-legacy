    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }
    int gcd = 1;
    int i = 1;
    for (; i <= x && i <= y; i++) {
        if (x % i == 0 && y % i == 0) {
            gcd = i;
        }
    }
    return x * y / gcd;
}