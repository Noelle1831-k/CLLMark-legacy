int getValidatedInteger() {
    int value;
    char buffer[100];
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &value) == 1) {
            return value;
        }
        printf("Invalid input. Please enter an integer: ");
    }
}