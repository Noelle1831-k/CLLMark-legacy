void removeAllSpaces(char* text) {
    int count = 0;
    for (int i = 0; text[i]; i++) {
        if (text[i] != ' ')
            text[count++] = text[i];
    }
    text[count] = '\0';
}