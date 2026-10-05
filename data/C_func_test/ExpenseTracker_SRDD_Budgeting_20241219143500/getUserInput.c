char* getUserInput() {
    char *input = (char *)malloc(256);
    printf("Enter command: ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = 0; 
    return input;
}