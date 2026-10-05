int get_integer_input(const char *prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while (getchar() != '\n'); 
    }
    while (getchar() != '\n'); 
    return value;
}