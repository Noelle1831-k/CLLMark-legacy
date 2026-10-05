void FileManager::saveToFile(const vector<string>& data, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < data.size(); i++) {
            file << data[i] << endl;
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file for writing: " << filename << endl;
    }
}