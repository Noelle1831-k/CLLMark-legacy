int validate_input(float input) {
    if (input <= 0) {
        printf("Invalid input: must be greater than 0.\n");
        return 0;
    }
    return 1;
}