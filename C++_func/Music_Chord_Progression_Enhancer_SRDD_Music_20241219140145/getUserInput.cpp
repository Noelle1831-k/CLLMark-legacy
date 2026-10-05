vector<string> UserInterface::getUserInput() {
    vector<string> chords;
    string chord;
    cout << "Enter your chord progression (type 'end' to finish):\n";
    while (true) {
        cin >> chord;
        if (chord == "end") break;
        chords.push_back(chord);
    }
    return chords;
}