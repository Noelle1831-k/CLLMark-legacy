string Utils::readFile(const string& filename) {
    ifstream file(filename);
    stringstream buffer;
    if (file.is_open()) {
        buffer << file.rdbuf();
        file.close();
    } else {
        cout << "Error opening file: " << filename << endl;
    }
    return buffer.str();
}