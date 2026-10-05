double getValidatedDouble() {
    double value;
    char buffer[100];
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%lf", &value) == 1) {
            return value;
        }
        printf("Invalid input. Please enter a number: ");
    }
}