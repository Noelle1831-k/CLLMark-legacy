int getIntInput(const char *prompt) {
    int input;
    printf("%s", prompt);
    while (scanf("%d", &input) != 1) {
        while (getchar() != '\n'); 
        printf("Invalid input. Please enter a number: ");
    }
    return input;
}