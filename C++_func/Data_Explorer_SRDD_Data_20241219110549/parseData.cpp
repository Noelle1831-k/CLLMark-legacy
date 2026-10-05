vector<vector<string>> Utility::parseData(const vector<string>& rawData) {
    cout << "Parsing data..." << endl;
    vector<vector<string>> parsedData;
    for (const string& line : rawData) {
        stringstream ss(line);
        string item;
        vector<string> row;
        while (getline(ss, item, ',')) {
            row.push_back(item);
        }
        parsedData.push_back(row);
    }
    return parsedData;
}