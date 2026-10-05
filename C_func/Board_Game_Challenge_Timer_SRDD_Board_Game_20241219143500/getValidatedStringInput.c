void getValidatedStringInput(char *input, int maxLength) {
    char buffer[100];
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%s", input) == 1 && strlen(input) < maxLength) {
            input[strcspn(input, "\n")] = '\0';
            return;
        }
        printf("Invalid input. Please enter a string with less than %d characters: ", maxLength);
    }
}