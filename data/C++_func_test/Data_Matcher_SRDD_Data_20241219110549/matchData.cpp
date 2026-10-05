void DataMatcher::matchData(const DataSet& dataset1, const DataSet& dataset2, const vector<string>& fields) {
    unordered_map<string, vector<string>> map1, map2;
    vector<vector<string>> data1 = dataset1.getData();
    vector<vector<string>> data2 = dataset2.getData();
    for (const auto& record : data1) {
        string key;
        for (const auto& field : fields) {
            key += record[stoi(field)] + "|";
        }
        map1[key] = record;
    }
    for (const auto& record : data2) {
        string key;
        for (const auto& field : fields) {
            key += record[stoi(field)] + "|";
        }
        if (map1.find(key) != map1.end()) {
            matchedRecords.push_back(record);
        }
    }
}