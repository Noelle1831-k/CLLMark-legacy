    int count = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size() - i; ++j) {
            if (a[i + j] >= a[i + j + 1]) {
                count++;
            }
        }
    }
    return count;
}