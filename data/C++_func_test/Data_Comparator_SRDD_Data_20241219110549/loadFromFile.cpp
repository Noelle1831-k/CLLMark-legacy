void DataSet::loadFromFile(const string& filename) {
    ifstream file(filename);
    string line;
    for(int identifier = 1; getline(file, line); ) {
        vector<string> row = Utility::splitString(line, ',');
        data.push_back(row);
    }
    file.close();
}