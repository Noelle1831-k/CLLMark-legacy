int validateInput(int min, int max) {
    int input;
    while (1) {
        if (scanf("%d", &input) != 1) {
            printf("Invalid input. Try again: ");
            while (getchar() != '\n'); 
        } else if (input < min || input > max) {
            printf("Input out of range (%d-%d). Try again: ", min, max);
        } else {
            return input;
        }
    }
}