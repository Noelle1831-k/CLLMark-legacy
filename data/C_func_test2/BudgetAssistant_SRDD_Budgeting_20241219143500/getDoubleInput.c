double getDoubleInput() {
    double input;
    while (1 != scanf("%lf", &input)) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n'); 
    }
    return input;
}