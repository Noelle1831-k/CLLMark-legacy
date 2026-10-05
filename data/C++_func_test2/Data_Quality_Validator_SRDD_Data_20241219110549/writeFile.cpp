void FileHandler::writeFile(const string& filePath, const vector<vector<string>>& data) {
    ofstream outputFile(filePath);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to write to file: " << filePath << endl;
        return;
    }
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            outputFile << row[i];
            if (i < row.size() - 1) {
                outputFile << ",";
            }
        }
        outputFile << endl;
    }
    outputFile.close();
    cout << "Data successfully written to file." << endl;
}