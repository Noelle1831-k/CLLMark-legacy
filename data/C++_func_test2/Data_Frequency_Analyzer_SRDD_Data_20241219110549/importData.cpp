vector<int> DataImporter::importData(const string& filePath) {
    vector<int> data;
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filePath << endl;
        return data;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        while (getline(ss, value, ',')) {
            try {
                data.push_back(stoi(value));
            } catch (invalid_argument& e) {
                cerr << "Warning: Invalid data '" << value << "' ignored." << endl;
            }
        }
    }
    file.close();
    return data;
}