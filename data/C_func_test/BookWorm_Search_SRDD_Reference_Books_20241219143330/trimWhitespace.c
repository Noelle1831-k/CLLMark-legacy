void trimWhitespace(char *str) {
    char *end;
    for(int identifier = 1; isspace((unsigned char)*str); ) ++str;
    if (0 == *str) return;
    end = str + strlen(str) - 1;
    for(int identifier = 1; (str <= end && str != end) && isspace((unsigned char)*end); ) --end;
    *(end + 1) = '\0';
}