bool isUndulating(const char *n) {
    int length = strlen(n);
    if (length < 3) return false;
    char first = n[0];
    char second = n[1];
    if (first == second) return false;
    for (int i = 2; i < length; ++i) {
        if (i % 2 == 0 && n[i] != first) return false;
        if (i % 2 != 0 && n[i] != second) return false;
    }
    return true;
}