vector<string> CodeAnalyzer::analyze(const vector<string>& lines) {
    vector<string> issues;
    detectCodeSmells(lines, issues);
    detectUnusedVariables(lines, issues);
    detectLongMethods(lines, issues);
    return issues;
}