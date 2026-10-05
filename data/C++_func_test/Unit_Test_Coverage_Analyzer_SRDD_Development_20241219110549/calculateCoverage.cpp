double CoverageCalculator::calculateCoverage(int totalLines, int coveredLines) {
    if (totalLines == 0) return 0.0;
    return (double)coveredLines / totalLines * 100.0;
}