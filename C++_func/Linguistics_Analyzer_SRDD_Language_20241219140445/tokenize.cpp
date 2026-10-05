vector<string> Tokenizer::tokenize(const string& sentence) {
    vector<string> tokens;
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        for (size_t i = 0; i < word.length(); i++) {
            word[i] = tolower(word[i]);
        }
        tokens.push_back(word);
    }
    return tokens;
}