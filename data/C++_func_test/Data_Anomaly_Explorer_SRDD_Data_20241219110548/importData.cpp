vector<vector<double>> DataImporter::importData(const string& filePath) {
    vector<vector<double>> data;
    ifstream file(filePath);
    string line;
    while (getline(file, line)) {
        vector<double> row;
        stringstream ss(line);
        string value;
        while (getline(ss, value, ',')) {
            row.push_back(stod(value));
        }
        data.push_back(row);
    }
    file.close();
    return data;
}