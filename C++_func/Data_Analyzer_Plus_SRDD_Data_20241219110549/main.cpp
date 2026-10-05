int main() {
    string fileName = "data.csv";
    DataAnalyzer dataAnalyzer;
    if (!dataAnalyzer.loadData(fileName)) {
        cout << "Error loading data." << endl;
        return -1;
    }
    dataAnalyzer.cleanData();
    dataAnalyzer.visualizeData();
    AdvancedAnalyzer advancedAnalyzer;
    advancedAnalyzer.predictData();
    advancedAnalyzer.testHypothesis();
    advancedAnalyzer.analyzeTrends();
    return 0;
}