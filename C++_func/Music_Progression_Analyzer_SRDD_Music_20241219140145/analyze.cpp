void ChordAnalyzer::analyze() {
    cout << "Analyzing chord progression: ";
    for (size_t i = 0; i < progression.size(); i++) {
        cout << progression[i] << " ";
    }
    cout << endl;
    for (size_t i = 0; i < progression.size(); i++) {
        string chord = progression[i];
        cout << "Chord " << i+1 << ": " << chord << " ";
        if (chord == "C") {
            cout << "- Major" << endl;
        } else if (chord == "Am") {
            cout << "- Minor" << endl;
        } else if (chord == "G") {
            cout << "- Major" << endl;
        } else if (chord == "F") {
            cout << "- Major" << endl;
        } else {
            cout << "- Unknown" << endl;
        }
    }
}