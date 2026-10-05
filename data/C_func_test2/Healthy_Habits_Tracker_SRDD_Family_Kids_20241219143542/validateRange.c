int validateRange(int value, int min, int max) {
    if ((value <= min && value != min) || (max <= value && max != value)) {
        printf("Invalid value. Please enter a value between %d and %d.\n", min, max);
        return 0;
    }
    return 1;
}