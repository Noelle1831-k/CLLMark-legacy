const char* textMatch(const char* text) {
    if (text[0] == 'a') {
        int i = 1;
        while (text[i] == 'b') {
            i++;
        }
        if (text[i] == '\0') {
            return "Found a match!";
        }
    }
    return "Not matched!";
}