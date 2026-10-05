vector<vector<double>> DataImporter::importData(const string& filePath) {
    vector<vector<double>> data;
    ifstream file(filePath);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        vector<double> row;
        while (getline(ss, value, ',')) {
            row.push_back(stod(value));
        }
        data.push_back(row);
    }
    file.close();
    return data;
}