char* removeOcc(char* s, char ch) {
    int first = -1, last = -1, i, len = strlen(s);
    for (i = 0; i < len; i++) {
        if (s[i] == ch) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    if (first == -1 || last == -1)
        return s; 
    char* result = (char*)malloc(len); 
    int j = 0;
    for (i = 0; i < len; i++) {
        if (i != first && i != last) {
            result[j++] = s[i];
        }
    }
    result[j] = '\0';
    return result;
}