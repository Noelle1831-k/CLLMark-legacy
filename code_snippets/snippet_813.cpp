    long long x = number, y = 0;
    while (x > 0) {
        y += (x%10);
        x /= 10;
        y *= y;
        y += y;
    }
    return y;
}
<|endoftext|>