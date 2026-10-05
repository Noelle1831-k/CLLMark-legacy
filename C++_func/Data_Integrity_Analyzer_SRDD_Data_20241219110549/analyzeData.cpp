void DataIntegrityAnalyzer::analyzeData() {
    DataLoader loader;
    DataChecker checker;
    ReportGenerator reportGen;
    loader.loadData();
    checker.checkConsistency();
    checker.checkAccuracy();
    checker.checkCompleteness();
    checker.checkValidity();
    reportGen.generateReport();
}