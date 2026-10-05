void ErrorIdentifier::findSentenceErrors(const string& text) {
    if (text.find("I") == string::npos) {
        cout << "Error: Missing subject in sentence." << endl;
    } else {
        cout << "Sentence structure is fine." << endl;
    }
}