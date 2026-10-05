int main() {
    UserInterface ui;
    AudioProcessor audioProcessor;
    ChordAnalyzer chordAnalyzer;
    Visualizer visualizer;
    string input = ui.getUserInput();
    if (!audioProcessor.loadAudioFile(input)) {
        cout << "Error: Unable to load audio file." << endl;
        return 1;
    }
    audioProcessor.processAudio();
    vector<string> chords = audioProcessor.detectChords();
    for (vector<string>::iterator it = chords.begin(); it != chords.end(); ++it) {
        string analyzedChord = chordAnalyzer.identifyChord(*it);
        visualizer.displayKeyboard(analyzedChord);
        visualizer.displayFretboard(analyzedChord);
        visualizer.generateChordDiagram(analyzedChord);
    }
    ui.showResults(chords);
    return 0;
}