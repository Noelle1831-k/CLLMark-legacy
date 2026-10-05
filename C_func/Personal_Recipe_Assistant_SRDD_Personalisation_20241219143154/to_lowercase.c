void to_lowercase(const char *input, char *output) {
    while (*input) {
        *output++ = tolower(*input++);
    }
    *output = '\0';
}