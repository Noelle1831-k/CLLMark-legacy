vector<string> CodeAnalyzer::findDuplicates(const string& content) {
    unordered_map<string, int> codeMap;
    vector<string> duplicates;
    string line;
    for (size_t i = 0; i < content.size(); ++i) {
        line += content[i];
        if (content[i] == '\n' || i == content.size() - 1) {
            if (codeMap[line]++ > 0) {
                duplicates.push_back(line);
            }
            line.clear();
        }
    }
    return duplicates;
}