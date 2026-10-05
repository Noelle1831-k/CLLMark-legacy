char* commonPrefix(char arr[][100], int n) {
    char *prefix = (char *)malloc(sizeof(char) * 100);
    
    int minLen = strlen(arr[0]);
    int i;
    int j;
    for (i = 1; i < n; i++) {
        if (strlen(arr[i]) < minLen) {
            minLen = strlen(arr[i]);
        }
    }
    for (i = 0; i < minLen; i++) {
        
        char current = arr[0][i];
        for (j = 1; j < n; j++) {
            if (arr[j][i] != current) {
                prefix[i] = '\0';
                return prefix;
            }
        }
        prefix[i] = current;
    }
    prefix[i] = '\0';
    return prefix;
}