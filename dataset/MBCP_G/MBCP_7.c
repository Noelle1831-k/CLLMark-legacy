char** findCharLong(const char* text, int* resultSize) {
    regex_t regex;
    const char* pattern = "\\b\\w{4,}\\b";
    regcomp(&regex, pattern, REG_EXTENDED);
    regmatch_t match;
    size_t nMatches = 0;
    size_t maxMatches = 10; 
    char** matches = malloc(maxMatches * sizeof(char*));
    const char* cursor = text;
    while (regexec(&regex, cursor, 1, &match, 0) == 0) {
        int len = match.rm_eo - match.rm_so;
        matches[nMatches] = strndup(cursor + match.rm_so, len);
        nMatches++;
        if (nMatches >= maxMatches) {
            maxMatches *= 2;
            matches = realloc(matches, maxMatches * sizeof(char*));
        }
        cursor += match.rm_eo;
    }
    regfree(&regex);
    *resultSize = (int)nMatches;
    return matches;
}
