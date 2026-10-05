int minimumLength(const char *s) {
    int freq[256] = {0};
    int length = strlen(s);
    for (int i = 0; i < length; ++i) {
        freq[(unsigned char)s[i]]++;
    }
    int minLength = length;
    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            int currentLength = length - freq[i];
            if (currentLength < minLength) {
                minLength = currentLength;
            }
        }
    }
    return minLength;
}