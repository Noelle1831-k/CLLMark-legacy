    if(n < 0)
        return false;
    int b = 1;
    while (n > 0) {
        if ((n % 2) == 0) {
            b *= 2;
            n /= 2;
        }
        else {
            b *= 3;
            n /= 3;
        }
    }
    return b % 2 == 0;
}