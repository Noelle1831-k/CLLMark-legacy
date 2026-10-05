int main() {
    UserInterface ui;
    AudioFile audio;
    EchoEffect echo;
    ui.displayMenu();
    int choice = ui.getUserChoice();
    while (choice != 0) {
        switch (choice) {
            case 1:
                audio.loadFile();
                break;
            case 2:
                if (audio.isLoaded()) {
                    echo.setDelay();
                    echo.setDecay();
                    echo.applyEcho(audio);
                } else {
                    cout << "No audio file loaded. Please load a file first." << endl;
                }
                break;
            case 3:
                if (audio.isLoaded()) {
                    audio.saveFile();
                } else {
                    cout << "No audio file loaded. Please load a file first." << endl;
                }
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        ui.displayMenu();
        choice = ui.getUserChoice();
    }
    cout << "Exiting Echomatic. Thank you for using our software!" << endl;
    return 0;
}