int main() {
    DataSet dataSet;
    dataSet.loadData("data.csv");
    DataQualityAnalyzer analyzer(dataSet);
    analyzer.checkConsistency();
    analyzer.checkAccuracy();
    analyzer.checkCompleteness();
    analyzer.checkValidity();
    analyzer.generateReport();
    return 0;
}