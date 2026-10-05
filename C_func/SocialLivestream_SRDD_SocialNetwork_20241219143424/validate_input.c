void validate_input(const char *input) {
    if (input == NULL || input[0] == '\0') {
        printf("Invalid input provided.\n");
        exit(EXIT_FAILURE);
    }
}