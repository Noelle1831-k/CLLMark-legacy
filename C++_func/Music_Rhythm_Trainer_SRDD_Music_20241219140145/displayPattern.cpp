void RhythmPattern::displayPattern() const {
    cout << "Rhythm Pattern: ";
    for (size_t i = 0; i < pattern.size(); i++) {
        cout << (pattern[i] ? "X" : "-") << " ";
    }
    cout << endl;
}