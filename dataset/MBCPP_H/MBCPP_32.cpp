    int i;
    int max = 2;
    for (i = 3; i < n; i++) {
        if (n % i == 0) {
            if (i > max) {
                max = i;
            }
        }
    }
    return max;
}