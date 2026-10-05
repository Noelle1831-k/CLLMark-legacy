    int count = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            count += 1;
        }
    }
    return count;
}