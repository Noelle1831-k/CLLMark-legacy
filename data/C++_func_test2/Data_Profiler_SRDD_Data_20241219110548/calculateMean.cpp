void StatisticsGenerator::calculateMean(const vector<vector<string>>& data) {
    for (size_t i = 0; i < data[0].size(); i++) {
        double sum = 0.0;
        int count = 0;
        for (size_t j = 0; j < data.size(); j++) {
            try {
                sum += stod(data[j][i]);
                count++;
            } catch (...) {
                continue;
            }
        }
        double mean = sum / count;
        cout << "Mean of column " << i << " is " << mean << endl;
    }
}