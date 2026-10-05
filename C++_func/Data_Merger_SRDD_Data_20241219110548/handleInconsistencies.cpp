void DataMerger::handleInconsistencies() {
    cout << "Handling inconsistencies..." << endl;
    for (size_t i = 0; i < datasets.size(); ++i) {
        vector<string> data = datasets[i].getData();
        for (size_t j = 0; j < data.size(); ++j) {
            data[j] = Utilities::convertDataType(data[j], "string");
        }
    }
}