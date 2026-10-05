int get_integer_input() {
    int value;
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Invalid input. Defaulting to 0.\n");
        return 0;
    }
    if (sscanf(buffer, "%d", &value) != 1) {
        printf("Invalid input. Defaulting to 0.\n");
        return 0;
    }
    return value;
}