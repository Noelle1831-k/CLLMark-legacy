void HistogramGenerator::generateHistogram(const map<int, int>& frequencyTable) {
    cout << "Histogram:" << endl;
    for (map<int, int>::const_iterator it = frequencyTable.begin(); it != frequencyTable.end(); ++it) {
        cout << it->first << ": ";
        for (int i = 0; i < it->second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}