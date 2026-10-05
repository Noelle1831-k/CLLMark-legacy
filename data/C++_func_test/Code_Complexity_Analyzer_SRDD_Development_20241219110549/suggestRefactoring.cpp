void RefactoringSuggestions::suggestRefactoring(const string& code) {
    cout << "Refactoring Suggestions:" << endl;
    if (code.find("if") != string::npos) {
        cout << "- Consider using switch-case for multiple conditions." << endl;
    }
    if (code.find("for") != string::npos) {
        cout << "- Consider using range-based loops for simplicity." << endl;
    }
}