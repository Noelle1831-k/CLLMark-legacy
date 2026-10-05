void CodeDuplication::detectDuplication(const string& code) {
    unordered_map<string, int> codeMap;
    string currentLine;
    for (size_t i = 0; i < code.length(); i++) {
        if (code[i] == ';') {
            codeMap[currentLine]++;
            currentLine.clear();
        } else {
            currentLine += code[i];
        }
    }
    for (const auto& entry : codeMap) {
        if (entry.second > 1) {
            cout << "Duplicated Code: " << entry.first << " - Count: " << entry.second << endl;
        }
    }
}