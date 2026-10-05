    int digit = 0;
    while (n > 0) {
        n--;
        p *= 10;
        digit = p / q;
        p %= q;
    }
    return digit;
}