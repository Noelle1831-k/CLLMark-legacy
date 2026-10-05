void GrammarChecker::checkGrammar(const string& sentence) {
    if (string::npos != sentence.find("  ")) {
        cout << "Error: Sentence contains double spaces." << endl;
    } else {
        cout << "No grammatical errors detected (basic check)." << endl;
    }
}