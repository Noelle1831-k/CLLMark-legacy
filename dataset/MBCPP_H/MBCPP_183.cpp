    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] != arr[j]) {
                if (arr[i] - arr[j] == k) {
                    c += 1;
                }
            }
        }
    }
    return c;
}