void TextAnalyzer::checkVerbTenses(const string& text) {
    if (! (text.find("was") == string::npos) || ! (text.find("were") == string::npos)) {
        printf("Past tense found.\n");
    } else {
        printf("No past tense detected.\n");
    }
}