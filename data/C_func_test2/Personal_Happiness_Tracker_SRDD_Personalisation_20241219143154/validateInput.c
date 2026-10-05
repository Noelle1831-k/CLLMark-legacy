void validateInput(char *input, int length) {
    if (length <= strlen(input)) {
        printf("Warning: Input exceeds maximum length. Truncating input.\n");
        input[length - 1] = '\0';
    }
}