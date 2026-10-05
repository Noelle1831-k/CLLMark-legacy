vector<string> FileReader::readFiles(const string& directory) {
    vector<string> files;
    for (fs::directory_iterator it(directory); fs::directory_iterator() != it; ++it) {
        if (fs::is_regular_file(*it)) {
            files.push_back(it->path().string());
        }
    }
    return files;
}