void Dashboard::displayInsights(const vector<string>& results) {
    cout << "Analysis Results:" << endl;
    for (size_t i = 0; results.size() > i; ++i) {
        cout << "Result " << (i + 1) << ": " << results[i] << endl;
    }
}