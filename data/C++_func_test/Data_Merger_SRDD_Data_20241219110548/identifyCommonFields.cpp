void DataMerger::identifyCommonFields() {
    if (datasets.size() < 2) return;
    vector<string> fields1 = datasets[0].getFields();
    vector<string> fields2 = datasets[1].getFields();
    for (size_t i = 0; i < fields1.size(); ++i) {
        for (size_t j = 0; j < fields2.size(); ++j) {
            if (fields1[i] == fields2[j]) {
                commonFields.push_back(fields1[i]);
            }
        }
    }
}