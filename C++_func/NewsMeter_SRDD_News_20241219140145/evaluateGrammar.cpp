void CredibilityAnalyzer::evaluateGrammar() {
    string content = article.getContent();
    if (content.find("is being") != string::npos) {
        cout << "Grammar issue detected: Passive voice used." << endl;
    }
}