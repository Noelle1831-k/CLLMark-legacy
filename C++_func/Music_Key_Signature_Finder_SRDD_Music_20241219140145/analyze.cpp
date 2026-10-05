bool MusicAnalyzer::analyze(const string &input, KeySignature &keySignature) {
    vector<string> majorKeys = {"C", "G", "D", "A", "E", "B", "F#", "C#", "F", "Bb", "Eb", "Ab", "Db", "Gb", "Cb"};
    vector<string> minorKeys = {"A", "E", "B", "F#", "C#", "G#", "D#", "A#", "D", "G", "C", "F", "Bb", "Eb", "Ab"};
    map<string, int> noteFrequency;
    vector<string> validNotes = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    istringstream stream(input);
    string noteOrChord;
    while (stream >> noteOrChord) {
        if (find(validNotes.begin(), validNotes.end(), noteOrChord) != validNotes.end()) {
            noteFrequency[noteOrChord]++;
        }
    }
    string mostLikelyKey;
    int maxScore = 0;
    for (const string &key : majorKeys) {
        int score = 0;
        for (const auto &pair : noteFrequency) {
            if (pair.first[0] == key[0]) { 
                score += pair.second * 2; 
            } else {
                score += pair.second;
            }
        }
        if (score > maxScore) {
            maxScore = score;
            mostLikelyKey = key;
        }
    }
    if (mostLikelyKey.empty()) {
        for (const string &key : minorKeys) {
            int score = 0;
            for (const auto &pair : noteFrequency) {
                if (pair.first[0] == key[0]) {
                    score += pair.second * 2;
                } else {
                    score += pair.second;
                }
            }
            if (score > maxScore) {
                maxScore = score;
                mostLikelyKey = key;
            }
        }
    }
    if (!mostLikelyKey.empty()) {
        keySignature.setKey(mostLikelyKey);
        return true;
    }
    return false;
}