void DataSummary::displaySummary() {
    cout << "Numerical Data Summary:" << endl;
    for (const auto& pair : numericalSummaries) {
        cout << "Variable: " << pair.first << endl;
        cout << "Mean: " << pair.second[0] << ", Median: " << pair.second[1] << ", Mode: " << pair.second[2] << ", Range: " << pair.second[3] << endl;
    }
    cout << "\nCategorical Data Summary:" << endl;
    for (const auto& pair : categoricalSummaries) {
        cout << "Variable: " << pair.first << endl;
        for (const auto& freq : pair.second) {
            cout << freq.first << ": " << freq.second << " ";
        }
        cout << endl;
    }
}