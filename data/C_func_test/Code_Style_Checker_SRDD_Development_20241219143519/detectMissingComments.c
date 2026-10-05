int detectMissingComments(const char *sourceCode) {
    int missingComments = 0;
    const char *commentStart = strstr(sourceCode, "
    const char *multiLineStart = strstr(sourceCode, "/*");
    if (!commentStart && !multiLineStart) {
        missingComments++;
    }
    return missingComments;
}