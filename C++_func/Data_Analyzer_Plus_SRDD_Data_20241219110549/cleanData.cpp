void DataAnalyzer::cleanData() {
    for (size_t i = 0; i < data.size(); i++) {
        data[i].erase(remove_if(data[i].begin(), data[i].end(), [](const string& s) {
            return s.empty();
        }), data[i].end());
    }
}