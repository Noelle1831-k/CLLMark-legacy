int validateRange(int value, int min, int max) {
    if (value < min || value > max) {
        printf("Invalid value. Please enter a value between %d and %d.\n", min, max);
        return 0;
    }
    return 1;
}