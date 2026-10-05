void removeChar(const char *input, char *output) {
    while (*input) {
        if (isalnum(*input)) {
            *output++ = *input;
        }
        input++;
    }
    *output = '\0';
}