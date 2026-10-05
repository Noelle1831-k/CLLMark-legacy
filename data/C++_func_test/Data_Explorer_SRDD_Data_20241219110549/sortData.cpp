void DataSet::sortData() {
    cout << "Sorting data..." << endl;
    sort(data.begin(), data.end(), [](vector<string> a, vector<string> b) {
        return a[1] < b[1];
    });
}