void DataSummary::addNumericalSummary(const string& variable, double mean, double median, double mode, double range) {
    numericalSummaries[variable] = {mean, median, mode, range};
}