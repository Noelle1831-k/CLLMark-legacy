int getValidatedInput(int min, int max) {
    int input;
    while (1) {
        if (scanf("%d", &input) == 1 && input >= min && input <= max) {
            return input;
        }
        printf("Invalid input. Please enter a number between %d and %d: ", min, max);
        while (getchar() != '\n'); 
    }
}