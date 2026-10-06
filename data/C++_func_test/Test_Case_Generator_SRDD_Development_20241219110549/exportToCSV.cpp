void ExportManager::exportToCSV(const vector<TestCase>& testCases, const string& filename) {
    ofstream file(filename.c_str());
    if (file.is_open()) {
        for (size_t i = 0; i < testCases.size(); i++) {
            file << testCases[i].serializeToCSV() << "\n";
        }
        file.close();
    }
}