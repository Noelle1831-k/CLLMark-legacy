void AdvancedAnalyzer::predictData() {
    cout << "Performing predictive modeling..." << endl;
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {1, 2, 2.8, 4.1, 5.3};
    double mean_x = StatisticsUtils::calculateMean(x);
    double mean_y = StatisticsUtils::calculateMean(y);
    double numerator = 0.0;
    double denominator = 0.0;
    for (size_t i = 0; i < x.size(); i++) {
        numerator += (x[i] - mean_x) * (y[i] - mean_y);
        denominator += pow(x[i] - mean_x, 2);
    }
    double slope = numerator / denominator;
    double intercept = mean_y - slope * mean_x;
    cout << "Linear regression model: y = " << slope << " * x + " << intercept << endl;
}