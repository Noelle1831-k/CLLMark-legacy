string Utils::readFile(const string& filePath) {
    ifstream file(filePath.c_str());
    if (!file.is_open()) {
        cerr << "Error: Could not open the file " << filePath << endl;
        return "";
    }
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}