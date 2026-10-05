void FileManager::exportData(const string& filePath, const vector<vector<string>>& data) {
    ofstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file for export: " << filePath << endl;
        return;
    }
    for (const auto& record : data) {
        for (size_t i = 0; i < record.size(); ++i) {
            file << record[i];
            if (i < record.size() - 1) {
                file << ",";
            }
        }
        file << endl;
    }
    file.close();
}