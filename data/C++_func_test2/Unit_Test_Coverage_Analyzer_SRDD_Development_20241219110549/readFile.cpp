vector<string> FileAnalyzer::readFile(const string& filePath) {
    vector<string> lines;
    ifstream file(filePath);
    string line;
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filePath << endl;
        return lines;
    }
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}