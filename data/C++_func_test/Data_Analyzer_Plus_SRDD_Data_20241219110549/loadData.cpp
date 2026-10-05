bool DataAnalyzer::loadData(const string& fileName) {
    ifstream file(fileName);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        vector<string> row;
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }
    return !data.empty();
}