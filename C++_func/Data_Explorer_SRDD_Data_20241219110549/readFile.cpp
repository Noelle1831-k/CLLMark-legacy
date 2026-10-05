vector<string> Utility::readFile(const string& filename) {
    cout << "Reading file: " << filename << endl;
    vector<string> lines;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}