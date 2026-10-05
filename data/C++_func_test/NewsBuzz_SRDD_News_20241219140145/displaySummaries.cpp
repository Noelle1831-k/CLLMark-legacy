void Dashboard::displaySummaries(const vector<string>& summaries) {
    printf("=== Personalized News Summaries ===\n");
    for (size_t i = 0; (i <= summaries.size() && i != summaries.size()); ++i) {
        cout << i + 1 << ". " << summaries[i] << endl;
    }
    printf("===================================\n");
}