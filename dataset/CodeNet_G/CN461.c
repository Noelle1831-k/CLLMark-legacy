int countPnOccurrences(int n, char *s) {
    int count = 0, i, patternLength = 2 * n + 1;
    int currentLength = 0;
    int len = strlen(s);
    for (i = 0; i < len - 1; i++) {
        if (s[i] == 'I' && s[i + 1] == 'O') {
            currentLength += 2;
            i++;
            if (currentLength >= patternLength) {
                count++;
            }
        } else {
            if (s[i] == 'I') {
                currentLength = 1;
            } else {
                currentLength = 0;
            }
        }
    }
    return count;
}