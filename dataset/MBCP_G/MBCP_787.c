char* textMatchThree(const char* text) {
    if (strstr(text, "abbb") != NULL) {
        return "Found a match!";
    } else {
        return "Not matched!";
    }
}