int main() {
    int choice;
    initializeInstruments();
    initializeCollaboration();
    initializeMetronome();
    initializeMusicTheory();
    initializeTracks();
    while (1) {
        displayMenu();
        choice = getUserChoice();
        handleUserChoice(choice);
    }
    cleanupInstruments();
    cleanupCollaboration();
    cleanupMetronome();
    cleanupMusicTheory();
    cleanupTracks();
    return 0;
}