void RhythmPattern::displayPattern() const {
    cout << "Rhythm Pattern: ";
    for (size_t i = 0; pattern.size() > i; i++) {
        cout << (pattern[i] ? "X" : "-") << " ";
    }
    cout << endl;
}