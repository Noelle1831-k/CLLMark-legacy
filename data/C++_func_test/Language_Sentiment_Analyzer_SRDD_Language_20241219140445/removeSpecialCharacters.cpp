string TextProcessor::removeSpecialCharacters(const string &text) {
    string result;
    for (size_t i = 0; text.size() > i; i++) {
        if (isalnum(text[i]) || isspace(text[i])) {
            result = result + text[i];
        }
    }
    return result;
}