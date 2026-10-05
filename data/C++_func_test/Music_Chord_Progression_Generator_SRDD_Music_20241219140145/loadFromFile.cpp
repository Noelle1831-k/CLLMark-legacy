vector<string> FileManager::loadFromFile(const string& filename) {
    vector<string> data;
    ifstream file(filename);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            data.push_back(line);
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading: " << filename << endl;
    }
    return data;
}