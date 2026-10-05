void charFrequency(const char *str, int freq[256]) {
    memset(freq, 0, sizeof(int) * 256);
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
}