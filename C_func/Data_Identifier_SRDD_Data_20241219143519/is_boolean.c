int is_boolean(const char *str) {
    return (strcasecmp(str, "true") == 0 || strcasecmp(str, "false") == 0);
}