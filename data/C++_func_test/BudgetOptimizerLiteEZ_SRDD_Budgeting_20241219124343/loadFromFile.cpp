void FileManager::loadFromFile(string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "Loading data from " << filename << "...\n";
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error: Unable to open file for loading.\n";
    }
}