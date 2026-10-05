bool Utilities::fileExists(string filename) {
    ifstream file(filename);
    return file.good();
}