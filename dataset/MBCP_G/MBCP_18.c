char* removeDirtyChars(char* str, char* secondString) {
    int hash[256] = {0};
    char* dst = str;
    char* src = str;
    while (*secondString) {
        hash[(unsigned char)*secondString++] = 1;
    }
    while (*src) {
        if (!hash[(unsigned char)*src]) {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
    return str;
}