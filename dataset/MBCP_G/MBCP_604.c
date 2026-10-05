void reverseWords(char *s) {
    int start = 0, end = 0, len = strlen(s);
    char result[len + 1];
    while (end < len) {
        while (end < len && s[end] != ' ') end++;
        int wordEnd = end - 1;
        while (wordEnd >= start) {
            strncat(result, &s[wordEnd], 1);
            wordEnd--;
        }
        if (s[end] == ' ') strncat(result, " ", 1);
        end++;
        start = end;
    }
    memset(s, 0, len);
    strcpy(s, result);
    start = 0;
    end = len - 1;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}