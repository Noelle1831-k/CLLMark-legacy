const char* textLowercaseUnderscore(const char* text) {
    int len = strlen(text);
    for (int i = 0; i < len - 1; i++) {
        if (islower(text[i]) && text[i + 1] == '_') {
            int j = i + 2;
            while (j < len && islower(text[j])) {
                j++;
            }
            if (j == len || (j < len && text[j] != '_')) {
                return "Found a match!";
            }
        }
    }
    return "Not matched!";
}
