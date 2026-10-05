char* read_input() {
    char *input = malloc(100 * sizeof(char));
    if (!input) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    fgets(input, 100, stdin);
    *(input + strcspn(input, "\n")) = '\0'; 
    return input;
}