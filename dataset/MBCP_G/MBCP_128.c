char** longWords(int n, const char* str, int* resultSize) {
    char* tempStr = strdup(str);
    char* token = strtok(tempStr, " ");
    char** result = malloc(sizeof(char*) * 100); 
    int count = 0;
    while (token != NULL) {
        if (strlen(token) > n) {
            result[count] = strdup(token);
            count++;
        }
        token = strtok(NULL, " ");
    }
    free(tempStr);
    *resultSize = count;
    return result;
}