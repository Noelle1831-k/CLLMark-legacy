bool Dataset::loadDataset(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    string line;
    if (getline(file, line)) {
        stringstream ss(line);
        string varName;
        while (getline(ss, varName, ',')) {
            variableNames.push_back(varName);
        }
    }
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
    return true;
}