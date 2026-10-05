void BeatMaker::createBeat() {
    cout << "Creating beat..." << endl;
    char continueAdding = 'y';
    while (continueAdding == 'y') {
        displayAvailableSounds();
        int choice = getSoundChoice();
        if (choice >= 0 && choice < sounds.size()) {
            sequencer.addSound(sounds[choice]);
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << "Add another sound? (y/n): ";
        cin >> continueAdding;
    }
    cout << "Beat created." << endl;
}