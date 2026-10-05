void Utils::writeFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
    } else {
        cout << "Error writing to file: " << filename << endl;
    }
}