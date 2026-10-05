void CSVHandler::writeCSV(const string& filename, const vector<vector<string>>& data) {
    ofstream file(filename);
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            file << data[i][j];
            if (j < data[i].size() - 1) file << ",";
        }
        file << "\n";
    }
}