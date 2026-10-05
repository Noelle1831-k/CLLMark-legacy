vector<int> FileAnalyzer::identifyTestedLines(const string& testFilePath) {
    vector<string> lines = readFile(testFilePath);
    vector<int> testedLines;
    for (size_t i = 0; i < lines.size(); i++) {
        if (lines[i].find("TEST(") != string::npos) {
            testedLines.push_back(i + 1);
        }
    }
    return testedLines;
}