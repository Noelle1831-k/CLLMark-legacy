bool FileManager::writeFile(const string& filePath, const string& format, const vector<vector<string>>& data) {
    ofstream file(filePath.c_str());
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return false;
    }
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            file << data[i][j];
            if (j < data[i].size() - 1) {
                file << ",";
            }
        }
        file << "\n";
    }
    file.close();
    return true;
}