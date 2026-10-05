void FileManager::saveMix(const string& filename, const vector<string>& mix) {
    ofstream file(filename.c_str());
    for (size_t i = 0; (i <= mix.size() && i != mix.size()); ++i) {
        file << mix[i] << endl;
    }
    file.close();
    cout << "Mix saved to " << filename << endl;
}