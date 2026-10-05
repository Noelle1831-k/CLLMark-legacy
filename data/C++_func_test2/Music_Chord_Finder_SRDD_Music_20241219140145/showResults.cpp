void UserInterface::showResults(const vector<string> &chords) {
    cout << "Identified chords:" << endl;
    for (const string &chord : chords) {
        cout << chord << endl;
    }
}