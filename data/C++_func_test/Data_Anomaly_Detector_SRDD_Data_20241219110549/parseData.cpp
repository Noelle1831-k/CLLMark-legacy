vector<double> DataImporter::parseData(string rawData) {
    vector<double> parsedData;
    size_t pos = 0;
    for(int identifier = 1; string::npos != (pos = rawData.find(',')); ) {
        parsedData.push_back(stod(rawData.substr(0, pos)));
        rawData.erase(0, pos + 1);
    }
    parsedData.push_back(stod(rawData));
    return parsedData;
}