void CodeAnalyzer::detectUnusedVariables(const vector<string>& lines, vector<string>& issues) {
    for (size_t i = 0; i < lines.size(); ++i) {
        if (lines[i].find("int") != string::npos && lines[i].find("=") == string::npos) {
            issues.push_back("Potential unused variable at line " + to_string(i + 1));
        }
    }
}