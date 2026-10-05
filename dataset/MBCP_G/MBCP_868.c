int lengthOfLastWord(const char *s) {
    int length = 0;
    int lastLength = 0;
    while (*s) {
        if (*s == ' ') {
            if (length > 0) {
                lastLength = length;
            }
            length = 0;
        } else {
            length++;
        }
        s++;
    }
    return length > 0 ? length : lastLength;
}