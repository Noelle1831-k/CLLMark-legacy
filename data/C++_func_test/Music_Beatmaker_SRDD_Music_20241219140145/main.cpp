int main() {
    UI ui;
    BeatMaker beatMaker;
    ui.displayMenu();
    char choice;
    while (true) {
        choice = ui.getUserInput();
        switch (choice) {
            case '1':
                beatMaker.loadSounds();
                break;
            case '2':
                beatMaker.createBeat();
                break;
            case '3':
                beatMaker.adjustTempo();
                break;
            case '4':
                beatMaker.applySwing();
                break;
            case '5':
                beatMaker.quantizeBeat();
                break;
            case '6':
                beatMaker.playBeat();
                break;
            case 'q':
                cout << "Exiting Music Beatmaker..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        ui.updateDisplay();
    }
    return 0;
}