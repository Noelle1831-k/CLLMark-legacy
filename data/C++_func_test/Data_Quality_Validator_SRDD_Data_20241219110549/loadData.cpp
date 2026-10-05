void DataValidator::loadData(const string& filePath) {
    cout << "Loading data from file: " << filePath << endl;
    dataset = fileHandler.readFile(filePath);
}