int main() {
    DataImporter importer;
    DataAnalyzer analyzer;
    DataSummary summary;
    vector<vector<string>> data = importer.importData("data.csv");
    if (data.empty() || data[0].empty()) {
        cerr << "Error: Data is empty or missing header." << endl;
        return 1;
    }
    cout << "Available variables: ";
    for (size_t i = 0; i < data[0].size(); i++) {
        cout << data[0][i] << " ";
    }
    cout << endl;
    vector<string> variables;
    string input;
    cout << "Enter variables to analyze (comma-separated): ";
    getline(cin, input);
    stringstream ss(input);
    string variable;
    while (getline(ss, variable, ',')) {
        variables.push_back(variable);
    }
    for (size_t i = 0; i < variables.size(); i++) {
        variable = variables[i];
        variable.erase(remove(variable.begin(), variable.end(), ' '), variable.end());
        if (find(data[0].begin(), data[0].end(), variable) == data[0].end()) {
            cerr << "Error: Variable " << variable << " does not exist in the dataset." << endl;
            continue;
        }
        if (analyzer.isNumerical(data, variable)) {
            double mean = analyzer.calculateMean(data, variable);
            double median = analyzer.calculateMedian(data, variable);
            double mode = analyzer.calculateMode(data, variable);
            double range = analyzer.calculateRange(data, variable);
            summary.addNumericalSummary(variable, mean, median, mode, range);
        } else {
            map<string, int> frequency = analyzer.calculateFrequency(data, variable);
            summary.addCategoricalSummary(variable, frequency);
        }
    }
    summary.displaySummary();
    return 0;
}