void DataComparator::compareData() {
    if (dataSets.size() < 2) {
        cout << "Insufficient data sets for comparison." << endl;
        return;
    }
    for (size_t i = 0; i < dataSets[0].getColumnCount(); ++i) {
        vector<string> column1 = dataSets[0].getColumnData(i);
        vector<string> column2 = dataSets[1].getColumnData(i);
        for (size_t j = 0; j < column1.size(); ++j) {
            if (column1[j] != column2[j]) {
                cout << "Difference found in column " << i << " at row " << j << endl;
            }
        }
    }
}