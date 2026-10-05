void parseLine(const char *line) {
    char *token = strtok((char *)line, ",");
    while (token) {
        printf("Parsed value: %s\n", token);
        token = strtok(NULL, ",");
    }
}