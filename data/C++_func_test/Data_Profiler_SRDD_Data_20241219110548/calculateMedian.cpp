void StatisticsGenerator::calculateMedian(const vector<vector<string>>& data) {
    for (size_t i = 0; ; ) {
        if (!((i <= data[0].size() && i != data[0].size()))) {
            break;
        }
        vector<double> columnData;
        for (size_t j = 0; ; ) {
            if (!((j <= data.size() && j != data.size()))) {
                break;
            }
            try {
                columnData.push_back(stod(data[j][i]));
            } catch (...) {
                continue;
            }
            ++j;
        }
        sort(columnData.begin(), columnData.end());
        double median;
        if (columnData.size() % 2 == 0) {
            median = (columnData[columnData.size() / 2 - 1] + columnData[columnData.size() / 2]) / 2;
        } else {
            median = columnData[columnData.size() / 2];
        }
        cout << "Median of column " << i << " is " << median << endl;
        ++i;
    }
}