void DataMerger::mergeDataVertically() {
    if (commonFields.empty()) return;
    map<string, vector<string>> mergedDataMap;
    for (size_t i = 0; i < datasets.size(); ++i) {
        vector<string> data = datasets[i].getData();
        for (size_t j = 0; j < data.size(); ++j) {
            vector<string> fields = Utilities::splitString(data[j], ',');
            for (size_t k = 0; k < fields.size(); ++k) {
                mergedDataMap[commonFields[k]].push_back(fields[k]);
            }
        }
    }
    for (map<string, vector<string>>::iterator it = mergedDataMap.begin(); it != mergedDataMap.end(); ++it) {
        cout << it->first << ": ";
        for (size_t i = 0; i < it->second.size(); ++i) {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
}