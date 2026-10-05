int main() {
    string inputType;
    cout << "Enter input type (MIDI/Manual): ";
    cin >> inputType;
    vector<string> chordProgression;
    if (inputType == "MIDI") {
        string filePath;
        cout << "Enter MIDI file path: ";
        cin >> filePath;
        MIDIParser midiParser(filePath);
        chordProgression = midiParser.parse();
    } else if (inputType == "Manual") {
        cout << "Enter chord progression (space separated, end with 'end'): ";
        string chord;
        while (cin >> chord && chord != "end") {
            chordProgression.push_back(chord);
        }
    } else {
        cout << "Invalid input type!" << endl;
        return 1;
    }
    ChordAnalyzer chordAnalyzer(chordProgression);
    chordAnalyzer.analyze();
    HarmonicAnalyzer harmonicAnalyzer(chordProgression);
    harmonicAnalyzer.analyze();
    Visualizer visualizer(chordProgression);
    visualizer.display();
    return 0;
}