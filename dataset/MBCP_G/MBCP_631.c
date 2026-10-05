void replaceSpaces(char *text) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            text[i] = '_';
        } else if (text[i] == '_') {
            text[i] = ' ';
        }
    }
}