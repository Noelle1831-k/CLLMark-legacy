void Dashboard::displaySummaries(const vector<string>& summaries) {
    cout << "=== Personalized News Summaries ===" << endl;
    for (size_t i = 0; i < summaries.size(); i++) {
        cout << i + 1 << ". " << summaries[i] << endl;
    }
    cout << "===================================" << endl;
}