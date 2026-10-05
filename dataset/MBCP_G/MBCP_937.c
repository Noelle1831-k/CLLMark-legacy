char maxChar(const char *str) {
    int count[256] = {0};
    int maxCount = 0;
    char result = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            result = (char)i;
        }
    }
    return result;
}