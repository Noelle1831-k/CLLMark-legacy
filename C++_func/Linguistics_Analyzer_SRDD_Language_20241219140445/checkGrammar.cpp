void GrammarChecker::checkGrammar(const string& sentence) {
    if (sentence.find("  ") != string::npos) {
        cout << "Error: Sentence contains double spaces." << endl;
    } else {
        cout << "No grammatical errors detected (basic check)." << endl;
    }
}