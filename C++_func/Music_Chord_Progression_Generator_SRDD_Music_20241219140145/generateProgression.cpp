vector<string> ChordGenerator::generateProgression(const string& key, const string& mood) {
    Key k(key);
    Mood m(mood);
    vector<string> scale = k.getScale();
    vector<string> patterns = m.getChordPatterns();
    vector<string> progression;
    for (int i = 0; i < patterns.size(); i++) {
        int index = i % scale.size();
        progression.push_back(scale[index] + patterns[i]);
    }
    return progression;
}