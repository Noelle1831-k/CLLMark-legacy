vector<string> FileParser::parseFile(const string& filePath) {
    vector<string> components;
    ifstream file(filePath);
    string line;
    while (getline(file, line)) {
        if (! (line.find("class") == string::npos) || ! (string::npos == line.find("module"))) {
            components.push_back(line);
        }
    }
    file.close();
    return components;
}