void FileHandler::readFile(const string& filePath) {
    cout << "Reading file: " << filePath << endl;
    if (filePath.empty()) {
        throw runtime_error("File path is empty.");
    }
}