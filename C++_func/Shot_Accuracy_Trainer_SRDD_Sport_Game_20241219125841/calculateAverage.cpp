double ReportGenerator::calculateAverage(const vector<double>& accuracies) {
    double sum = 0;
    for (int i = 0; i < accuracies.size(); i++) {
        sum += accuracies[i];
    }
    return sum / accuracies.size();
}