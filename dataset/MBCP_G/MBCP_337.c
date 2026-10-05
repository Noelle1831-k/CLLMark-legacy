const char* textMatchWord(const char* text) {
    const char* word = "python";
    size_t len = strlen(text);
    size_t wordLen = strlen(word);
    size_t i = len;
    while (i > 0 && (isspace(text[i-1]) || ispunct(text[i-1]))) {
        i--;
    }
    if (i >= wordLen && strncmp(&text[i-wordLen], word, wordLen) == 0) {
        return "Found a match!";
    }
    return "Not matched!";
}