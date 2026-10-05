vector<vector<int>> DataManager::loadOccupancyData(const string &filename) {
    vector<vector<int>> data;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return data;
    }
    string line;
    int lineCount = 0;
    while (getline(file, line)) {
        vector<int> row;
        stringstream ss(line);
        string value;
        while (getline(ss, value, ',')) {
            try {
                row.push_back(stoi(value));
            } catch (invalid_argument &e) {
                cerr << "Warning: Non-integer value found on line " << lineCount + 1 << endl;
                row.push_back(0);  
            }
        }
        data.push_back(row);
        lineCount++;
    }
    file.close();
    if (data.empty()) {
        cerr << "Warning: No valid data found in the file." << endl;
    }
    return data;
}