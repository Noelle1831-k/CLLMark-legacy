vector<string> Utils::splitString(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}