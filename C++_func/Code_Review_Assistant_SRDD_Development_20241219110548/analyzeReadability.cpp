void CodeAnalyzer::analyzeReadability(const string& code) {
    for (int i = 0; i < code.length(); i++) {
        if (code[i] == ' ') {
            cout << "Readability improved at position " << i << endl;
        }
    }
}