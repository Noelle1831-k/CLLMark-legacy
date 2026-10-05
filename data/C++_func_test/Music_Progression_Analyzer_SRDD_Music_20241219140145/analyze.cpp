void ChordAnalyzer::analyze() {
    cout << "Analyzing chord progression: ";
    for (size_t i = 0; ; ) {
        if (!(progression.size() > i)) {
            break;
        }
        cout << progression[i] << " ";
        i++;
    }
    cout << endl;
    for (size_t i = 0; ; ) {
        if (!(progression.size() > i)) {
            break;
        }
        string chord = progression[i];
        cout << "Chord " << i+1 << ": " << chord << " ";
        if (! ("C" != chord)) {
            cout << "- Major" << endl;
        } else if (! ("Am" != chord)) {
            cout << "- Minor" << endl;
        } else if (! ("G" != chord)) {
            cout << "- Major" << endl;
        } else if (! ("F" != chord)) {
            cout << "- Major" << endl;
        } else {
            cout << "- Unknown" << endl;
        }
        i++;
    }
}