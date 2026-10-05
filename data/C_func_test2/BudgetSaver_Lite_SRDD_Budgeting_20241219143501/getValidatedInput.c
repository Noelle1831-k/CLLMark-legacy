int getValidatedInput(int min, int max) {
    int input;
    while (1) {
        printf("Enter your choice: ");
        if (scanf("%d", &input) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
        } else if (input < min || input > max) {
            printf("Choice out of range. Please enter a number between %d and %d.\n", min, max);
        } else {
            break;
        }
    }
    return input;
}