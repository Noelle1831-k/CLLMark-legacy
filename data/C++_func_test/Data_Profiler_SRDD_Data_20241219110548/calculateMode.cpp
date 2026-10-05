void StatisticsGenerator::calculateMode(const vector<vector<string>>& data) {
    for (size_t i = 0; i < data[0].size(); i++) {
        map<double, int> frequency;
        for (size_t j = 0; j < data.size(); j++) {
            try {
                double value = stod(data[j][i]);
                frequency[value]++;
            } catch (...) {
                continue;
            }
        }
        double mode = 0;
        int maxCount = 0;
        for (map<double, int>::iterator it = frequency.begin(); it != frequency.end(); ++it) {
            if (it->second > maxCount) {
                maxCount = it->second;
                mode = it->first;
            }
        }
        cout << "Mode of column " << i << " is " << mode << endl;
    }
}