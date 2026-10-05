void DataProfiler::analyzeData() {
    analyzer.detectDataTypes(data);
    analyzer.findMissingValues(data);
    analyzer.identifyOutliers(data);
}