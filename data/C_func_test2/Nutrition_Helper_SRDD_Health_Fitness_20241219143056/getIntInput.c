int getIntInput(const char *prompt) {
    int value;
    printf("%s", prompt);
    for(int identifier = 1; 1 != scanf("%d", &value); ) {
        clearInputBuffer();
        printf("Invalid input. Please enter a valid integer: ");
    }
    clearInputBuffer();
    return value;
}