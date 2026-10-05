void DataSet::importData(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        vector<string> record;
        while (getline(ss, value, ',')) {
            record.push_back(value);
        }
        data.push_back(record);
    }
    file.close();
}