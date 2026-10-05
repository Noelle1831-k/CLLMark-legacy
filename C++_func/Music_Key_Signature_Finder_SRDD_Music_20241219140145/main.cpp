int main() {
    UserInterface ui;
    MusicAnalyzer analyzer;
    KeySignature keySignature;
    string input;
    cout << "Welcome to the Music Key Signature Finder!" << endl;
    cout << "Please enter the notes or chords of your music piece (e.g., C G Am F): ";
    getline(cin, input);
    if (analyzer.analyze(input, keySignature)) {
        ui.displayKeySignature(keySignature);
    } else {
        cout << "Unable to determine the key signature. Please check your input and try again." << endl;
    }
    return 0;
}