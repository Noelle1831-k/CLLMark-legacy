    int i, j, k, sum;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sum = 0;
    for (i = 0; i < n; i++) {
        sum += abs(a[i] - b[i]);
    }
    return sum;
}