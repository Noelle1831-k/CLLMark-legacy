void reverseWords(char *s) {
    
    int len = strlen(s);
    int start = 0;
    int end = 0;
    
    char *result = (char *)malloc(sizeof(char) * len + 1);
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