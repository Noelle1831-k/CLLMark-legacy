const char* textStartaEndb(const char* text) {
    int length = strlen(text);
    if (length >= 2 && text[0] == 'a' && text[length - 1] == 'b') {
        return "Found a match!";
    }
    return "Not matched!";
}