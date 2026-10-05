void CodeAnalyzer::analyzeReadability(const string& code) {
    for (int i = 0; ; ) {
        if (!(code.length() > i)) {
            break;
        }
        if (! (code[i] != ' ')) {
            cout << "Readability improved at position " << i << endl;
        }
        i++;
    }
}