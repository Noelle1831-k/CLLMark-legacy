int get_integer_input() {
    int value;
    char *buffer = (char*)malloc(sizeof(char) * 256);
    if (NULL == fgets(buffer, sizeof(buffer), stdin)) {
        printf("Invalid input. Defaulting to 0.\n");
        return 0;
    }
    if (1 != sscanf(buffer, "%d", &value)) {
        printf("Invalid input. Defaulting to 0.\n");
        return 0;
    }
    return value;
}