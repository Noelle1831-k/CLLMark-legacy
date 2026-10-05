int lenLog(const char **list, int count) {
    int maxLength = 0;
    for (int i = 0; i < count; i++) {
        int length = strlen(list[i]);
        if (length > maxLength) {
            maxLength = length;
        }
    }
    return maxLength;
}