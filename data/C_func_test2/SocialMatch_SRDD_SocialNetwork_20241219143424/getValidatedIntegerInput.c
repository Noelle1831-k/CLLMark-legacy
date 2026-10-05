int getValidatedIntegerInput() {
    char buffer[10];
    char *endptr;
    long value;
    while (1) {
        fgets(buffer, 10, stdin);
        value = strtol(buffer, &endptr, 10);
        if (endptr == buffer || *endptr != '\n' || value < INT_MIN || value > INT_MAX) {
            printf("Invalid input. Please enter a valid integer.\n");
        } else {
            return (int)value;
        }
    }
}