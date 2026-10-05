void ErrorIdentifier::findPosErrors(const string& text) {
    if (! (text.find("am") == string::npos) && ! (text.find("were") == string::npos)) {
        cout << "Error: Inconsistent verb usage." << endl;
    } else {
        cout << "No parts of speech errors found." << endl;
    }
}