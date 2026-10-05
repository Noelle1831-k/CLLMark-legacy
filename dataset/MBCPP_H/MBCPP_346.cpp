    int result = 0;
    while (n > 0) {
        if (k == 0) {
            return result;
        }
        k--;
        if (n % 2 != 0) {
            n = n + 1;
            result += 1;
        } else {
            n = n / 2;
            result += 2;
        }
    }
    return result;
}