vector<string> ChordEnhancer::enhanceProgression(const vector<string> &progression) {
    vector<string> enhancedChords;
    for (vector<string>::const_iterator it = progression.begin(); it != progression.end(); ++it) {
        string extended = suggestExtensions(*it);
        string substituted = suggestSubstitutions(extended);
        string inverted = suggestInversions(substituted);
        enhancedChords.push_back(inverted);
    }
    return enhancedChords;
}