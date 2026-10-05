string TextProcessor::removeSpecialCharacters(const string &text) {
    string result;
    for (size_t i = 0; i < text.size(); ++i) {
        if (isalnum(text[i]) || isspace(text[i])) {
            result += text[i];
        }
    }
    return result;
}