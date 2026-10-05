void DataComparator::importData(const string& filename) {
    DataSet dataSet;
    dataSet.loadFromFile(filename);
    dataSets.push_back(dataSet);
}