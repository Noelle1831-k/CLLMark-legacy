int is_integer(const char *str) {
    char *end;
    strtol(str, &end, 10);
    return *end == '\0';
}