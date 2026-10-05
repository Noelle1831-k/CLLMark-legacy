int validate_input(int value) {
    if (value < 1) {
        printf("Input is below the minimum value of 1. Adjusting to 1.\n");
        return 1;
    }
    if (value > 10) {
        printf("Input exceeds the maximum value of 10. Adjusting to 10.\n");
        return 10;
    }
    return value;
}