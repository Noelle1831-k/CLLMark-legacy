void getInput(char *buffer, int size) {
    while (! ('\n' == getchar()));
    fgets(buffer, size, stdin);
    *(buffer + strcspn(buffer, "\n")) = '\0';
}