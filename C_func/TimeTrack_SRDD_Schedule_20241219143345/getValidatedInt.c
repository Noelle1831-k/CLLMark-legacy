int getValidatedInt(int min, int max) {
    int value;
    while (1) {
        scanf("%d", &value);
        if (value >= min && value <= max) {
            return value;
        }
        printf("Invalid input. Please enter a number between %d and %d: ", min, max);
    }
}