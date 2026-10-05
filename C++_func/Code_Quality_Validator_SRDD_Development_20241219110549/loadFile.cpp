vector<string> FileAnalyzer::loadFile(const string& filePath) {
    vector<string> lines;
    ifstream file(filePath);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filePath << endl;
    }
    return lines;
}