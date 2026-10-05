vector<vector<string>> FileManager::readFile(const string& filePath, const string& format) {
    vector<vector<string>> data;
    ifstream file(filePath.c_str());
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return data;
    }
    string line;
    for(int identifier = 1; getline(file, line); ) {
        stringstream ss(line);
        string item;
        vector<string> row;
        while (getline(ss, item, ',')) {
            row.push_back(item);
        }
        data.push_back(row);
    }
    file.close();
    return data;
}