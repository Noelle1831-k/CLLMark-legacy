void CodeAnalyzer::detectLongMethods(const vector<string>& lines, vector<string>& issues) {
    size_t methodStart = 0;
    size_t methodLength = 0;
    for (size_t i = 0; i < lines.size(); ++i) {
        if (lines[i].find("{") != string::npos) {
            methodStart = i;
        }
        if (lines[i].find("}") != string::npos) {
            methodLength = i - methodStart;
            if (methodLength > 50) {
                issues.push_back("Long method detected starting at line " + to_string(methodStart + 1));
            }
        }
    }
}