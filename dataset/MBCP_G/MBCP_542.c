void fillSpaces(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.') {
            text[i] = ':';
        }
    }
}