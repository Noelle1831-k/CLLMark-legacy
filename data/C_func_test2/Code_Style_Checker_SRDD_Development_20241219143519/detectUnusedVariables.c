int detectUnusedVariables(const char *sourceCode) {
    int unusedVars = 0;
    const char *keywords[] = {"int", "char", "float", "double", "long", "short", NULL};
    const char delimiters[] = " \n\t;(),{}";
    char codeCopy[strlen(sourceCode) + 1];
    strcpy(codeCopy, sourceCode);
    char *token = strtok(codeCopy, delimiters);
    while (token != NULL) {
        for (int i = 0; keywords[i] != NULL; i++) {
            if (strcmp(token, keywords[i]) == 0) {
                char *varName = strtok(NULL, delimiters);
                if (varName && strstr(sourceCode, varName) == NULL) {
                    unusedVars++;
                }
            }
        }
        token = strtok(NULL, delimiters);
    }
    return unusedVars;
}