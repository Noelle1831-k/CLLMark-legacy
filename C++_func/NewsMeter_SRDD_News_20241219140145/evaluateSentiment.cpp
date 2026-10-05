void CredibilityAnalyzer::evaluateSentiment() {
    string content = article.getContent();
    if (content.find("catastrophic") != string::npos) {
        cout << "Negative sentiment detected." << endl;
    } else {
        cout << "Neutral sentiment detected." << endl;
    }
}