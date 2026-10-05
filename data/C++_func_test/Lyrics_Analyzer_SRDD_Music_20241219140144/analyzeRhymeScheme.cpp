void RhymeAnalyzer::analyzeRhymeScheme(const string& lyrics) {
    stringstream ss(lyrics);
    string line;
    int lineIndex = 0;
    while (getline(ss, line)) {
        string lastWord;
        stringstream lineStream(line);
        while (lineStream >> lastWord) {
            lastWord.erase(remove_if(lastWord.begin(), lastWord.end(), ::ispunct), lastWord.end());
        }
        if (rhymeMap.find(lastWord) == rhymeMap.end()) {
            rhymeMap[lastWord] = 'A' + lineIndex;
            rhymeScheme += rhymeMap[lastWord];
        } else {
            rhymeScheme += rhymeMap[lastWord];
        }
        lineIndex++;
    }
}