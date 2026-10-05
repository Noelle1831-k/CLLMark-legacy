vector<int> CoverageCalculator::highlightUncoveredSections(const vector<int>& coveredLines, int totalLines) {
    vector<int> uncoveredLines;
    for (int i = 1; i <= totalLines; i++) {
        if (find(coveredLines.begin(), coveredLines.end(), i) == coveredLines.end()) {
            uncoveredLines.push_back(i);
        }
    }
    return uncoveredLines;
}