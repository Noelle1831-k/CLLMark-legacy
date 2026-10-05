int main() {
    DataImporter importer;
    TrendAnalyzer analyzer;
    PredictiveModeler modeler;
    HypothesisTester tester;
    TrendForecaster forecaster;
    if (importer.importData("data.xlsx")) {
        cout << "Data import successful." << endl;
    } else {
        cerr << "Error: Failed to import data from Excel file." << endl;
        return 1;
    }
    analyzer.analyzeTrends();
    modeler.buildModel();
    modeler.predict();
    tester.testHypothesis();
    forecaster.forecastTrends();
    cout << "Data Trend Analyzer Plus execution completed." << endl;
    return 0;
}