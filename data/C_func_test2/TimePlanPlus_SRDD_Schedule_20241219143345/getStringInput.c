void getStringInput(char *buffer, int length) {
    fgets(buffer, length, stdin);
    *(buffer + strcspn(buffer, "\n")) = '\0';
}