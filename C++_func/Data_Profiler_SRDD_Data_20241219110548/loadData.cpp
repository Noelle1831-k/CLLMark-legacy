void DataProfiler::loadData(const string& filename) {
    data = Utilities::readCSV(filename);
}