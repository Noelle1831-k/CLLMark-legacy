int getValidatedInput(int min, int max) {
    int input;
    while (1) {
        scanf("%d", &input);
        if (min <= input && input <= max) {
            return input;
        }
        printf("Invalid input. Please enter a number between %d and %d: ", min, max);
    }
}