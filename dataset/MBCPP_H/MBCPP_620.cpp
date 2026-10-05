    int max = 0;
    for (int i = 0; i < n; i++) {
        int subset = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] % a[j] == 0) {
                subset += 1;
            }
        }
        if (subset > max) {
            max = subset;
        }
    }
    return max;
}