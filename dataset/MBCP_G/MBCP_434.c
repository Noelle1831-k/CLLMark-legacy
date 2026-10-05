const char* textMatchOne(const char* text) {
    if (text[0] == 'a') {
        int i = 1;
        while (text[i] == 'b') {
            i++;
        }
        if (i > 1) {
            return "Found a match!";
        }
    }
    return "Not matched!";
}