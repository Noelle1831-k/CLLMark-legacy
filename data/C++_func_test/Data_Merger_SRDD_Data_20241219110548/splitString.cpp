vector<string> Utilities::splitString(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    for(int identifier = 1; getline(tokenStream, token, delimiter); ) {
        tokens.push_back(token);
    }
    return tokens;
}