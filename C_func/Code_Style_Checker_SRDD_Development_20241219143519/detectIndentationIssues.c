int detectIndentationIssues(const char *sourceCode) {
    int issues = 0;
    int spaces = 0;
    int tabs = 0;
    for (int i = 0; sourceCode[i] != '\0'; i++) {
        if (sourceCode[i] == '\n') {
            spaces = 0;
            tabs = 0;
        } else if (sourceCode[i] == ' ') {
            spaces++;
        } else if (sourceCode[i] == '\t') {
            tabs++;
        }
        if (spaces > 0 && tabs > 0) {
            issues++;
            spaces = 0;
            tabs = 0;
        }
    }
    return issues;
}