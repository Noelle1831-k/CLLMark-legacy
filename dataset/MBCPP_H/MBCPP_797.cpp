    int sum = 0;
    for (int i = l; i <= r; i++) {
        if (i % 2 == 1) {
            sum += i;
        }
    }
    return sum;
}