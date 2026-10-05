static int detect_long_methods(const char *source_code) {
    int long_method_count = 0;
    char *token = strtok((char *)source_code, "{");
    while (token != NULL) {
        if (strlen(token) > 200) {
            long_method_count++;
        }
        token = strtok(NULL, "{");
    }
    return long_method_count;
}