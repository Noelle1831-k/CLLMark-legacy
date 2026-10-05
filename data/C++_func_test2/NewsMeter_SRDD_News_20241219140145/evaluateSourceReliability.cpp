void CredibilityAnalyzer::evaluateSourceReliability() {
    string source = article.getSource();
    if (source == "www.environmentalnews.com") {
        cout << "Source is reliable." << endl;
    } else {
        cout << "Source is questionable." << endl;
    }
}