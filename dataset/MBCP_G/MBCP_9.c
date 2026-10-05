int findRotations(const char* str) {
    int n = strlen(str);
    char* temp = (char*)malloc(2 * n + 1);
    if (!temp) return -1; 
    strcpy(temp, str);
    strcat(temp, str);
    for (int i = 1; i <= n; i++) {
        if (strncmp(str, temp + i, n) == 0) {
            free(temp);
            return i;
        }
    }
    free(temp);
    return n;
}