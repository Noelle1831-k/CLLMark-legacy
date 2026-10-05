void CredibilityAnalyzer::evaluateBias() {
    string content = article.getContent();
    if (content.find("climate change denial") != string::npos) {
        cout << "Article shows potential bias: Climate change denial." << endl;
    } else {
        cout << "Article seems unbiased." << endl;
    }
}