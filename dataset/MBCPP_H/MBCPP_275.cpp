    int pos = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == n) {
            pos = i;
        }
    }
    return pos + m;
}