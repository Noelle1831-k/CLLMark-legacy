vector<string> MIDIParser::parse() {
    vector<string> chordProgression;
    cout << "Parsing MIDI file: " << filePath << endl;
    chordProgression.push_back("C");
    chordProgression.push_back("G");
    chordProgression.push_back("Am");
    chordProgression.push_back("F");
    return chordProgression;
}