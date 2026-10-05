    int i, j;
    for (i = 0; i < l.size() - 1; i++) {
        if (l[i] + 1 != l[i + 1]) {
            return false;
        }
    }
    return true;
}