    int res = 0;
    sort(ar.begin(), ar.end());
    for (int i = 0; i < n; ++i) {
        int count = 1;
        for (int j = i + 1; j < n; ++j) {
            if (ar[i] == ar[j]) ++count;
            else break;
        }
        res = max(res, count);
    }
    return res;
}