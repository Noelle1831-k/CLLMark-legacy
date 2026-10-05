void UserInterface::handleUserInput() {
    int choice;
    cin >> choice;
    string chord;
    int duration, bpm, semitones;
    string filename;
    switch (choice) {
        case 1:
            cout << "Enter chord: ";
            cin >> chord;
            cout << "Enter duration: ";
            cin >> duration;
            creator->addChord(chord, duration);
            break;
        case 2:
            creator->arrangeSequence();
            break;
        case 3:
            cout << "Enter new tempo: ";
            cin >> bpm;
            creator->adjustTempo(bpm);
            break;
        case 4:
            cout << "Enter semitones to transpose: ";
            cin >> semitones;
            creator->transpose(semitones);
            break;
        case 5:
            cout << "Enter filename for MIDI export: ";
            cin >> filename;
            creator->exportToMIDI(filename);
            break;
        case 6:
            cout << "Enter filename for sheet music export: ";
            cin >> filename;
            creator->exportToSheetMusic(filename);
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}