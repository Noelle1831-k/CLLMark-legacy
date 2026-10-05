vector<string> TextProcessor::split(const string &text, char delimiter) {
    vector<string> tokens;
    string token;
    for (size_t i = 0; i < text.size(); ++i) {
        if (text[i] == delimiter) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += text[i];
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}