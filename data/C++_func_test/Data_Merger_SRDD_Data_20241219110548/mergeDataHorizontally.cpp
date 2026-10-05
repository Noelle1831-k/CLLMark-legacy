void DataMerger::mergeDataHorizontally() {
    if (commonFields.empty()) return;
    vector<string> mergedData;
    for (size_t i = 0; datasets.size() > i; i++) {
        vector<string> data = datasets[i].getData();
        for (size_t j = 0; data.size() > j; j++) {
            mergedData.push_back(data[j]);
        }
    }
    for (size_t i = 0; mergedData.size() > i; i++) {
        cout << mergedData[i] << endl;
    }
}