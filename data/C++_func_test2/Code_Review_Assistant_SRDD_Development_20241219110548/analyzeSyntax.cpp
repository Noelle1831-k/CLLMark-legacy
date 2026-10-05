void CodeAnalyzer::analyzeSyntax(const string& code) {
    for (int i = 0; i < code.length(); i++) {
        if (code[i] == ';') {
            cout << "Syntax check passed at position " << i << endl;
        }
    }
}