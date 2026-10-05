void TextAnalyzer::checkVerbTenses(const string& text) {
    if (text.find("was") != string::npos || text.find("were") != string::npos) {
        cout << "Past tense found." << endl;
    } else {
        cout << "No past tense detected." << endl;
    }
}