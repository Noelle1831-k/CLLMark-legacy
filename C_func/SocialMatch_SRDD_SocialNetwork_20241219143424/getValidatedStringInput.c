void getValidatedStringInput(char *input, int maxLength) {
    fgets(input, maxLength, stdin);
    input[strcspn(input, "\n")] = '\0'; 
}