char* findMaxLenEven(char* str) {
    char* token;
    char* maxWord = NULL;
    int maxLen = 0;
    token = strtok(str, " ");
    while (token != NULL) {
        int len = strlen(token);
        if (len % 2 == 0 && len > maxLen) {
            maxLen = len;
            maxWord = token;
        }
        token = strtok(NULL, " ");
    }
    if (maxWord == NULL) {
        return "-1";
    }
    return maxWord;
}