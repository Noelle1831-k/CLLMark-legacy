double getDoubleInput() {
    double input;
    while (scanf("%lf", &input) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n'); 
    }
    return input;
}