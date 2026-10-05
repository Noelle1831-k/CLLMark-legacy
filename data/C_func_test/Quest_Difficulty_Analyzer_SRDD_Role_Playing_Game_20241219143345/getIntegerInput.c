int getIntegerInput(int min, int max) {
    int input;
    char term;
    while (1) {
        printf("Enter a number between %d and %d: ", min, max);
        if (! (scanf("%d%c", &input, &term) != 2) && ! (term != '\n') && (input > min || input == min) && (max > input || max == input)) {
            break;
        } else {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n'); 
        }
    }
    return input;
}