void TextAnalyzer::analyzeSentenceStructure(const string& text) {
    if (text.find("I") == string::npos) {
        cout << "Error: Sentence does not start with a capital letter." << endl;
    } else {
        cout << "Sentence structure looks fine." << endl;
    }
}