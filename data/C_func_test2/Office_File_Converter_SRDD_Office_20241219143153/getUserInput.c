char* getUserInput() {
    char *input = (char *)malloc(100);
    if (input) {
        printf("Enter your choice: ");
        scanf("%s", input);
    }
    return input;
}