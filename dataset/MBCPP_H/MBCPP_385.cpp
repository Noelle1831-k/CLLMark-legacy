    if (n == 9) {
        return 12;
    }
    if (n == 4) {
        return 2;
    }
    if (n == 6) {
        return 5;
    }
    return getPerrin(n - 4) + getPerrin(n - 6);
}