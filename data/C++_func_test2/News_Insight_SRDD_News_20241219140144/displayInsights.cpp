void Dashboard::displayInsights(const vector<string>& results) {
    cout << "Analysis Results:" << endl;
    for (size_t i = 0; i < results.size(); i++) {
        cout << "Result " << (i + 1) << ": " << results[i] << endl;
    }
}