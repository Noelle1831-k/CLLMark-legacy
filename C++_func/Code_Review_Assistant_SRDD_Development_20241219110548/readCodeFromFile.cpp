string FileHandler::readCodeFromFile(const string& filename) {
    ifstream file(filename);
    string code, line;
    if (file.is_open()) {
        while (getline(file, line)) {
            code += line + "\n";
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    return code;
}