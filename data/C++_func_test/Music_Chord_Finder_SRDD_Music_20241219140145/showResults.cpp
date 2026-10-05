void UserInterface::showResults(const vector<string> &chords) {
    printf("Identified chords:\n");
    for (const string &chord : chords) {
        cout << chord << endl;
    }
}