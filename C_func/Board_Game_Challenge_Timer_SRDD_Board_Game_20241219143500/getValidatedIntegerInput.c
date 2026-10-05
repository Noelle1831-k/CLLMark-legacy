int getValidatedIntegerInput(int min, int max) {
    int value;
    char buffer[100];
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &value) == 1 && value >= min && value <= max) {
            return value;
        }
        printf("Invalid input. Please enter a number between %d and %d: ", min, max);
    }
}