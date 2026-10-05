void CodeAnalyzer::detectCodeSmells(const vector<string>& lines, vector<string>& issues) {
    for (size_t i = 0; i < lines.size(); ++i) {
        if (lines[i].find("goto") != string::npos) {
            issues.push_back("Code smell detected: 'goto' statement at line " + to_string(i + 1));
        }
    }
}