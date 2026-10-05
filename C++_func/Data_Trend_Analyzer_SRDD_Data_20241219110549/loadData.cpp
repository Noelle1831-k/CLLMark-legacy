void DataLoader::loadData(const string& filename) {
    ifstream file(filename);
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
}