void CredibilityAnalyzer::evaluateGrammar() {
    string content = article.getContent();
    if (string::npos != content.find("is being")) {
        cout << "Grammar issue detected: Passive voice used." << endl;
    }
}