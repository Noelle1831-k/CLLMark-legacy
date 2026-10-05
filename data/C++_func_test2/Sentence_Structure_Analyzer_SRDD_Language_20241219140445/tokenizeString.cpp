vector<string> tokenizeString(const string& str) {
    vector<string> tokens;
    stringstream ss(str);
    string word;
    while (ss >> word) {
        tokens.push_back(word);
    }
    return tokens;
}