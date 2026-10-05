int getIntInput(const char *prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        while (getchar() != '\n'); 
        printf("%s", prompt);
    }
    while (getchar() != '\n'); 
    return value;
}