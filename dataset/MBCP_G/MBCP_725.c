char** extractQuotation(const char* text1, int* resultSize) {
    regex_t regex;
    regmatch_t pmatch[2];
    const char* pattern = "\"([^\"]*)\"";
    int reti;
    char** result = NULL;
    *resultSize = 0;
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) return NULL;
    const char* ptr = text1;
    while ((reti = regexec(&regex, ptr, 2, pmatch, 0)) == 0) {
        int length = pmatch[1].rm_eo - pmatch[1].rm_so;
        char* match = (char*)malloc(length + 1);
        strncpy(match, ptr + pmatch[1].rm_so, length);
        match[length] = '\0';
        (*resultSize)++;
        result = (char**)realloc(result, sizeof(char*) * (*resultSize));
        result[(*resultSize) - 1] = match;
        ptr += pmatch[0].rm_eo;
    }
    regfree(&regex);
    return result;
}