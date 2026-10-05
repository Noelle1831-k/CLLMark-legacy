vector<string> ChordAnalyzer::analyzeProgression(const vector<string> &progression) {
    vector<string> analyzedChords;
    for (vector<string>::const_iterator it = progression.begin(); it != progression.end(); ++it) {
        if (chordKeyMap.find(*it) != chordKeyMap.end()) {
            analyzedChords.push_back(chordKeyMap[*it]);
        } else {
            analyzedChords.push_back("Unknown Chord");
        }
    }
    return analyzedChords;
}