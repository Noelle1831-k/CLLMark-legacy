void Dataset::loadData(const string& filename) {
    ifstream file(filename);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string value;
            vector<double> row;
            while (getline(ss, value, ',')) {
                row.push_back(stod(value));
            }
            data.push_back(row);
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
}