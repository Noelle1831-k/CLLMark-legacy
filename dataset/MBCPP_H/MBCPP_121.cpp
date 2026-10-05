    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            for (k = j + 1; k < n; k++) {
                if (a[i] + a[j] + a[k] == sum) {
                    return true;
                }
            }
        }
    }
    return false;
}