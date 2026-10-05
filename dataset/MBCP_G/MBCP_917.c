const char* textUppercaseLowercase(const char* text) {
    int i = 0;
    while (text[i] != '\0') {
        if (isupper(text[i])) {
            int j = i + 1;
            while (islower(text[j])) {
                j++;
            }
            if (j > i + 1) {
                return "Found a match!";
            }
        }
        i++;
    }
    return "Not matched!";
}