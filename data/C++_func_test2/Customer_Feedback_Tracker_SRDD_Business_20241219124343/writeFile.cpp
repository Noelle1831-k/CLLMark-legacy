void Utility::writeFile(const string &filename, const string &data) {
    ofstream file(filename.c_str());
    if (file.is_open()) {
        file << data;
        file.close();
        cout << "Data written to file: " << filename << endl;
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}