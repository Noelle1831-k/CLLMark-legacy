vector<vector<string>> DataLoader::loadData() {
    cout << "Loading data from file..." << endl;
    vector<vector<string>> data;
    ifstream file("data.csv");
    string line, word;
    if (file.is_open()) {
        while (getline(file, line)) {
            vector<string> row;
            stringstream str(line);
            while (getline(str, word, ',')) {
                row.push_back(word);
            }
            data.push_back(row);
        }
        file.close();
        cout << "Data loaded successfully." << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
    return data;
}