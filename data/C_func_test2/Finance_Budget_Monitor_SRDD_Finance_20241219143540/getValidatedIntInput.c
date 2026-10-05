int getValidatedIntInput() {
    int input;
    while (scanf("%d", &input) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n'); 
    }
    return input;
}