int CyclomaticComplexity::calculateComplexity(const string& code) {
    int complexity = 1; 
    for (size_t i = 0; i < code.length(); i++) {
        if (code[i] == 'i' && code.substr(i, 2) == "if") complexity++;
        if (code[i] == 'f' && code.substr(i, 3) == "for") complexity++;
        if (code[i] == 'w' && code.substr(i, 5) == "while") complexity++;
    }
    cout << "Cyclomatic Complexity: " << complexity << endl;
    return complexity;
}