void DataExplorer::exploreData() {
    cout << "Exploring data..." << endl;
    dataSet.filterData();
    dataSet.sortData();
    dataSet.groupData();
    dataSet.aggregateData();
}