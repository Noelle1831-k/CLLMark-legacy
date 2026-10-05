void FileHandler::writeFile(const string& filePath) {
    cout << "Writing file: " << filePath << endl;
    if (filePath.empty()) {
        throw runtime_error("File path is empty.");
    }
}