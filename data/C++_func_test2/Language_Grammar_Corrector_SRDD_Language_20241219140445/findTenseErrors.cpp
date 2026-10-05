void ErrorIdentifier::findTenseErrors(const string& text) {
    if (text.find("is") != string::npos && text.find("was") != string::npos) {
        cout << "Error: Tense inconsistency between present and past." << endl;
    } else {
        cout << "Tense usage is consistent." << endl;
    }
}