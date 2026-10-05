int FileAnalyzer::countLinesOfCode(const string& filePath) {
    vector<string> lines = readFile(filePath);
    int count = 0;
    for (size_t i = 0; i < lines.size(); i++) {
        if (!lines[i].empty() && lines[i].find_first_not_of(" \t") != string::npos) {
            count++;
        }
    }
    return count;
}