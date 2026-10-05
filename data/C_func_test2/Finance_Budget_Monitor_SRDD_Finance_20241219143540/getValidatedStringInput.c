void getValidatedStringInput(char *str, int maxLength) {
    while (1) {
        if (fgets(str, maxLength, stdin)) {
            size_t len = strlen(str);
            if (len > 0 && str[len - 1] == '\n') {
                str[len - 1] = '\0';
            }
            if (strlen(str) > 0) break;
        }
        printf("Invalid input. Please enter a valid string: ");
    }
}