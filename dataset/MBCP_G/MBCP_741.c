bool allCharactersSame(const char *s) {
    size_t len = strlen(s);
    for(size_t i = 1; i < len; ++i) {
        if(s[i] != s[0]) {
            return false;
        }
    }
    return true;
}