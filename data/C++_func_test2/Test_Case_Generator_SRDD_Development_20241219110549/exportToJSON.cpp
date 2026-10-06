void ExportManager::exportToJSON(const vector<TestCase>& testCases, const string& filename) {
    ofstream file(filename.c_str());
    if (file.is_open()) {
        file << "[";
        for (size_t i = 0; i < testCases.size(); i++) {
            file << testCases[i].serializeToJSON();
            if (i != testCases.size() - 1) file << ", ";
        }
        file << "]";
        file.close();
    }
}