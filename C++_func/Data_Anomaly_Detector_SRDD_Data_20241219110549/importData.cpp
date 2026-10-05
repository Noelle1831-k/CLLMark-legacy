vector<double> DataImporter::importData(string fileName) {
    ifstream inputFile(fileName);
    vector<double> data;
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return data;
    }
    string line;
    while (getline(inputFile, line)) {
        vector<double> parsedData = parseData(line);
        data.insert(data.end(), parsedData.begin(), parsedData.end());
    }
    inputFile.close();
    return data;
}