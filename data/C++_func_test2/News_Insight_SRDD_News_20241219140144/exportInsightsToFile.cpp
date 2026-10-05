void Dashboard::exportInsightsToFile(const vector<string>& results, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error exporting insights to file: " << filename << endl;
        return;
    }
    for (size_t i = 0; i < results.size(); i++) {
        file << "Result " << (i + 1) << ": " << results[i] << endl;
    }
    file.close();
}