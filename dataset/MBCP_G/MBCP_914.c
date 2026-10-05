bool isTwoAlter(const char *s) {
    int len = strlen(s);
    if (len < 2) return false;
    for (int i = 2; i < len; i++) {
        if (s[i] != s[i % 2]) {
            return false;
        }
    }
    return s[0] != s[1];
}