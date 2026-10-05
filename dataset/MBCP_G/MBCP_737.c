#define MAX_MATCHES 1
const char* checkStr(const char* str) {
    regex_t regex;
    regmatch_t matches[MAX_MATCHES];
    const char* pattern = "^[aeiouAEIOU]";
    int reti;
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        return "Error compiling regex";
    }
    reti = regexec(&regex, str, MAX_MATCHES, matches, 0);
    regfree(&regex);
    if (!reti) {
        return "Valid";
    } else if (reti == REG_NOMATCH) {
        return "Invalid";
    } else {
        return "Regex match failed";
    }
}