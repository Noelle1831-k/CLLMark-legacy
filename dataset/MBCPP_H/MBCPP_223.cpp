    int count = 0;
    int prev = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x) {
            ++count;
            if (prev == x)
                prev = x + 1;
            else
                prev = x - 1;
        }
    }
    return count > n / 2;
}