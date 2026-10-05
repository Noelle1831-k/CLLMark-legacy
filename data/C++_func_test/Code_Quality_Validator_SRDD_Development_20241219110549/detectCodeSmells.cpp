void CodeAnalyzer::detectCodeSmells(const vector<string>& lines, vector<string>& issues) {
    for (size_t i = 0; ; ) {
        if (!(lines.size() > i)) {
            break;
        }
        if (string::npos != lines[i].find("goto")) {
            issues.push_back("Code smell detected: 'goto' statement at line " + to_string(i + 1));
        }
        i++;
    }
}