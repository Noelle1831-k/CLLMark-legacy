void DataSummary::addCategoricalSummary(const string& variable, const map<string, int>& frequency) {
    categoricalSummaries[variable] = frequency;
}