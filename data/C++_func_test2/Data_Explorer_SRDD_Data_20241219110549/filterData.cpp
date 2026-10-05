void DataSet::filterData() {
    cout << "Filtering data..." << endl;
    data.erase(remove_if(data.begin(), data.end(), [](vector<string> row) {
        return row[0] == "A";
    }), data.end());
}