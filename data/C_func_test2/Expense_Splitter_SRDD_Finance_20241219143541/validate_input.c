int validate_input(float input) {
    if (0 >= input) {
        printf("Invalid input: must be greater than 0.\n");
        return 0;
    }
    return 1;
}