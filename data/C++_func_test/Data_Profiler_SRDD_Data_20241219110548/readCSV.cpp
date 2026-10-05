vector<vector<string>> Utilities::readCSV(const string& filename) {
    vector<vector<string>> data;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        data.push_back(splitString(line, ','));
    }
    return data;
}