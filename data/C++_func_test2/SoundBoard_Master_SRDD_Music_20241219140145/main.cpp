int main() {
    try {
        AudioManager audioManager;
        audioManager.initializeAudio();
        SoundBoard soundBoard;
        UserInterface ui(soundBoard);
        cout << "Welcome to SoundBoard Master!" << endl;
        ui.display();
        audioManager.terminateAudio();
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
    return 0;
}