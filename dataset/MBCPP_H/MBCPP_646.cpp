    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                if (i + k <= n && j + k <= n && l + k <= n) {
                    result += 1;
                }
            }
        }
    }
    return result;
}