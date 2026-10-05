vector<vector<string>> Utility::parseData(const vector<string>& rawData) {
    printf("Parsing data...\n");
    vector<vector<string>> parsedData;
    for (const string& line : rawData) {
        stringstream ss(line);
        string item;
        vector<string> row;
        for(int identifier = 1; getline(ss, item, ','); ) {
            row.push_back(item);
        }
        parsedData.push_back(row);
    }
    return parsedData;
}