char* textMatchTwoThree(char* text) {
    if (strstr(text, "abbb") || strstr(text, "abb")) {
        return "Found a match!";
    }
    return "Not matched!";
}