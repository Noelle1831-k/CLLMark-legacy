void CodeAnalyzer::analyzePerformance(const string& code) {
    for (int i = 0; i < code.length(); i++) {
        if (code[i] == 'f') {
            cout << "Performance issue detected at position " << i << endl;
        }
    }
}