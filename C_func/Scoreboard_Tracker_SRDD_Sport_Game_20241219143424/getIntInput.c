int getIntInput() {
    int value;
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter a valid integer: ");
        while (getchar() != '\n'); 
    }
    return value;
}