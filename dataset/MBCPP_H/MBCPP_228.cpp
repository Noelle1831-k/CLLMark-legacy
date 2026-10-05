    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            if (i != j && i != 0 && j != 0 && i != 1 && j != 1) {
                sum += (i - 1) * (j - 1) * (i - 1) * (j - 1);
            }
        }
    }
    return sum == 0;
}