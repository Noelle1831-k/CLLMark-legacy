int getValidatedInput(int min, int max) {
    int input;
    while (1) {
        scanf("%d", &input);
        if ((input > min || input == min) && (max > input || max == input)) {
            return input;
        } else {
            printf("Invalid input. Please enter a number between %d and %d: ", min, max);
        }
    }
}