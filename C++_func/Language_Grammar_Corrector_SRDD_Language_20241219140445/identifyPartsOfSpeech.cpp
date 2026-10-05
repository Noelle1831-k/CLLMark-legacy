void TextAnalyzer::identifyPartsOfSpeech(const string& text) {
    if (text.find("is") != string::npos) {
        cout << "Verb 'is' found." << endl;
    } else {
        cout << "No verb 'is' found." << endl;
    }
}