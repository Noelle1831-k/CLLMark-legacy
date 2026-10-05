void string_trim(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return;
    end = str + strlen(str) - 1;
    while (str < end && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;
}