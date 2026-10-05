void UIHandler::displayHeadlines() {
    vector<string> headlines = newsManager.getHeadlines();
    if (headlines.empty()) {
        cout << "No headlines available. Please check the news sources." << endl;
        return;
    }
    cout << "\n--- Latest Headlines ---\n";
    for (size_t i = 0; i < headlines.size(); i++) {
        cout << "- " << headlines[i] << endl;
    }
    cout << "-------------------------\n";
}