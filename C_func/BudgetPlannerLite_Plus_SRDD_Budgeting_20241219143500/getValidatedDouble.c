double getValidatedDouble() {
    double input;
    while (1) {
        if (scanf("%lf", &input) == 1 && input >= 0) {
            return input;
        }
        printf("Invalid input. Please enter a positive number: ");
        while (getchar() != '\n'); 
    }
}