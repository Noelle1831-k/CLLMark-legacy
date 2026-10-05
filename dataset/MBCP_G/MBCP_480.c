char getMaxOccuringChar(const char *str) {
    int count[256] = {0};
    int max = -1;
    char result;
    for (int i = 0; str[i]; i++) {
        count[(unsigned char)str[i]]++;
        if (max < count[(unsigned char)str[i]]) {
            max = count[(unsigned char)str[i]];
            result = str[i];
        }
    }
    return result;
}