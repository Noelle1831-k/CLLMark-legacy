void sanitize_input(char *input) {
    char *newline = strchr(input, '\n');
    if (newline) {
        *newline = '\0';
    }
}