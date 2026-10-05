    if (n == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr1[i] == arr2[j]) {
                    return true;
                }
            }
        }
    }
    return false;
}