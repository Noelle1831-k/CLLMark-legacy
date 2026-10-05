int getValidatedIntegerInput() {
    int value;
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while (getchar() != '\n'); 
    }
    return value;
}