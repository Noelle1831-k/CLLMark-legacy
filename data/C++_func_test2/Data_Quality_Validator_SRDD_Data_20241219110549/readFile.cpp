vector<vector<string>> FileHandler::readFile(const string& filePath) {
    vector<vector<string>> data;
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file: " << filePath << endl;
        return data;
    }
    string line;
    while (getline(inputFile, line)) {
        vector<string> row;
        stringstream ss(line);
        string cell;
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }
    inputFile.close();
    cout << "Data successfully loaded from file." << endl;
    return data;
}