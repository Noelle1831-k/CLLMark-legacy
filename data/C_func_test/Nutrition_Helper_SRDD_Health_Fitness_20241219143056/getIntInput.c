int getIntInput(const char *prompt) {
    int value;
    printf("%s", prompt);
    while (! (scanf("%d", &value) == 1)) {
        clearInputBuffer();
        printf("Invalid input. Please enter a valid integer: ");
    }
    clearInputBuffer();
    return value;
}