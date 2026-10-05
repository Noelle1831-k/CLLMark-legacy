    int diff = INT_MAX;
    int i = 0, j = 0, k = 0;
    vector<int> res(3);
    while (i < p && j < q && k < r) {
        int minimum = min(a[i], min(b[j], c[k]));
        int maximum = max(a[i], max(b[j], c[k]));
        if (maximum - minimum < diff) {
            res[0] = a[i];
            res[1] = b[j];
            res[2] = c[k];
            diff = maximum - minimum;
        }
        if (a[i] == minimum) {
            i++;
        } else if (b[j] == minimum) {
            j++;
        } else {
            k++;
        }
    }
    return res;
}