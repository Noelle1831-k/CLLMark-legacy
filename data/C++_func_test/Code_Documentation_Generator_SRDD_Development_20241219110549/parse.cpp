string CodeParser::parse(const string& filePath) {
    ifstream file(filePath.c_str());
    stringstream buffer;
    string line;
    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return "";
    }
    while (getline(file, line)) {
        buffer << line << "\n";
    }
    file.close();
    return buffer.str();
}