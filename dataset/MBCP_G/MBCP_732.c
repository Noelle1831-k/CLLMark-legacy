char* replaceSpecialchar(char* text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.') {
            text[i] = ':';
        }
    }
    return text;
}