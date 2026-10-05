void FileHandler::writeToFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error writing to file: " << filename << endl;
        return;
    }
    file << content << endl;
    file.close();
}