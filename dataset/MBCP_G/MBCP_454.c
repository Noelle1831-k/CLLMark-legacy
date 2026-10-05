const char* textMatchWordz(const char* text) {
    if (strchr(text, 'z') != NULL) {
        return "Found a match!";
    }
    return "Not matched!";
}