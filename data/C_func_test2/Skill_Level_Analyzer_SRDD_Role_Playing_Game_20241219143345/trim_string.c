void trim_string(char* str) {
    char* end;
    while (*str == ' ') str++;
    if (*str == 0) return;
    end = str + strlen(str) - 1;
    while (end > str && *end == ' ') end--;
    *(end + 1) = '\0';
}