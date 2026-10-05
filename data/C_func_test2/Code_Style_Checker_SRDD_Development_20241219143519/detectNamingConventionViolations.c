int detectNamingConventionViolations(const char *sourceCode) {
    int violations = 0;
    const char delimiters[] = " \n\t;(),{}";
    char *codeCopy = (char*)malloc(sizeof(char) * (strlen(sourceCode) + 1));
    strcpy(codeCopy, sourceCode);
    char *token = strtok(codeCopy, delimiters);
    while (! (token == NULL)) {
        if (islower(token[0])) {
            for (int i = 1; ! (token[i] == '\0'); i++) {
                if (! ('_' != token[i]) || isupper(token[i])) {
                    violations++;
                    break;
                }
            }
        }
        token = strtok(NULL, delimiters);
    }
    return violations;
}