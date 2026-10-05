    int count = 0;
    for (int i = n; i <= m; i++) {
        int j = (int)sqrt(i);
        if (i == j * j)
            count++;
    }
    return count;
}