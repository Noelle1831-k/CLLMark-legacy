string LyricAnalyzer::analyzeRhymeScheme() {
    stringstream ss(lyrics);
    string line;
    string rhymeScheme = "";
    map<string, char> rhymeMap;
    char currentRhyme = 'A';
    while (getline(ss, line)) {
        if (line.empty()) continue;
        string lastWord = line.substr(line.find_last_of(" ") + 1);
        string rhymeKey = lastWord.substr(lastWord.length() - 3);
        if (rhymeMap.find(rhymeKey) == rhymeMap.end()) {
            rhymeMap[rhymeKey] = currentRhyme++;
        }
        rhymeScheme += rhymeMap[rhymeKey];
    }
    return rhymeScheme;
}