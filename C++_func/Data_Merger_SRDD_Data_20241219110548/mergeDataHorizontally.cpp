void DataMerger::mergeDataHorizontally() {
    if (commonFields.empty()) return;
    vector<string> mergedData;
    for (size_t i = 0; i < datasets.size(); ++i) {
        vector<string> data = datasets[i].getData();
        for (size_t j = 0; j < data.size(); ++j) {
            mergedData.push_back(data[j]);
        }
    }
    for (size_t i = 0; i < mergedData.size(); ++i) {
        cout << mergedData[i] << endl;
    }
}