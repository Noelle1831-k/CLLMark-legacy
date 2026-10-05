void StatisticsGenerator::calculateMedian(const vector<vector<string>>& data) {
    for (size_t i = 0; i < data[0].size(); i++) {
        vector<double> columnData;
        for (size_t j = 0; j < data.size(); j++) {
            try {
                columnData.push_back(stod(data[j][i]));
            } catch (...) {
                continue;
            }
        }
        sort(columnData.begin(), columnData.end());
        double median;
        if (columnData.size() % 2 == 0) {
            median = (columnData[columnData.size() / 2 - 1] + columnData[columnData.size() / 2]) / 2;
        } else {
            median = columnData[columnData.size() / 2];
        }
        cout << "Median of column " << i << " is " << median << endl;
    }
}