bool chklist(const char *lst[], int size) {
    if (size <= 1) return true;
    for (int i = 1; i < size; i++) {
        if (strcmp(lst[0], lst[i]) != 0) {
            return false;
        }
    }
    return true;
}