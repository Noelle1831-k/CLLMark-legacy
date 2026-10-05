double getValidatedDoubleInput() {
    double input;
    while (scanf("%lf", &input) != 1) {
        printf("Invalid input. Please enter a valid number: ");
        while (getchar() != '\n'); 
    }
    return input;
}