vector<string> Utility::splitString(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    for(int identifier = 1; getline(ss, token, delimiter); ) {
        tokens.push_back(token);
    }
    return tokens;
}