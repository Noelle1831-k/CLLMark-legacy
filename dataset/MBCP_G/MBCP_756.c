const char* textMatchZeroOne(const char* text) {
    int len = strlen(text);
    for (int i = 0; i < len - 1; i++) {
        if (text[i] == 'a' && (text[i + 1] == 'b' || text[i + 1] != 'b')) {
            return "Found a match!";
        }
    }
    if (text[len - 1] == 'a') {
        return "Found a match!";
    }
    return "Not matched!";
}