int main() {
    cout << "Welcome to the Music Loop Creator!" << endl;
    Instrument piano;
    piano.loadSound("piano.wav");
    NoteSequence sequence;
    sequence.addNote("C4");
    sequence.addNote("E4");
    sequence.addNote("G4");
    GridLayout grid;
    grid.addPattern(sequence);
    grid.displayGrid();
    LoopManager loopManager;
    loopManager.setTempo(120);
    loopManager.setLoopLength(16);
    loopManager.exportLoop("my_loop.wav");
    return 0;
}