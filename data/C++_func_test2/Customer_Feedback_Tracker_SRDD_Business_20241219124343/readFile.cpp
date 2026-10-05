void Utility::readFile(const string &filename) {
    ifstream file(filename.c_str());
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}