char firstRepeatedChar(const char *str) {
    int count[256] = {0};
    for (int i = 0; i < strlen(str); i++) {
        if (count[(unsigned char)str[i]] == 1) {
            return str[i];
        }
        count[(unsigned char)str[i]]++;
    }
    return '\0';
}