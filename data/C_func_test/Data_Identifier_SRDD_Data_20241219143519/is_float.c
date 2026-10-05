int is_float(const char *str) {
    char *end;
    strtod(str, &end);
    return *end == '\0';
}