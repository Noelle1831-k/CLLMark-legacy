DataSet FileHandler::readCSV(const string& filename) {
    DataSet dataset;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        dataset.addData(line);
    }
    file.close();
    return dataset;
}