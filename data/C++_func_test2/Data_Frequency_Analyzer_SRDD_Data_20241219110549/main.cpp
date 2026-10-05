int main() {
    string filePath;
    cout << "Enter the path to the data file: ";
    cin >> filePath;
    DataImporter importer;
    vector<int> data = importer.importData(filePath);
    if (data.empty()) {
        cerr << "Error: No data imported. Please check the file path and format." << endl;
        return 1;
    }
    FrequencyAnalyzer analyzer;
    map<int, int> frequencyTable = analyzer.analyzeFrequency(data);
    analyzer.generateFrequencyTable(frequencyTable);
    HistogramGenerator histogram;
    histogram.generateHistogram(frequencyTable);
    return 0;
}