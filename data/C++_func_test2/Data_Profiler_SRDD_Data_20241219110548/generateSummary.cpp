void DataProfiler::generateSummary() {
    statsGen.calculateMean(data);
    statsGen.calculateMedian(data);
    statsGen.calculateMode(data);
    statsGen.calculateStandardDeviation(data);
}