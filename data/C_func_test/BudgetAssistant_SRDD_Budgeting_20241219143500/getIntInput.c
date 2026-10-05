int getIntInput() {
    int input;
    while (scanf("%d", &input) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while (getchar() != '\n'); 
    }
    return input;
}