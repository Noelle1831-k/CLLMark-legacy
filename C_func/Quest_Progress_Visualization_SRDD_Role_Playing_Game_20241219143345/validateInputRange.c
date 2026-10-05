int validateInputRange(int min, int max) {
    int value;
    do {
        scanf("%d", &value);
        if (value < min || value > max) {
            printf("Invalid input. Please enter a number between %d and %d: ", min, max);
        }
    } while (value < min || value > max);
    return value;
}