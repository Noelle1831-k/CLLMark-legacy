double validate_input() {
    double value;
    while (1) {
        if (scanf("%lf", &value) != 1 || value < 0) {
            printf("Invalid input. Enter a positive number: ");
            while (getchar() != '\n'); 
        } else {
            break;
        }
    }
    return value;
}