void getInput(char *buffer, int size) {
    while (getchar() != '\n');
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}