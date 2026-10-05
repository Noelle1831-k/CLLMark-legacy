int main() {
    srand(static_cast<unsigned int>(time(0))); 
    UserInterface ui;
    AudioManager audioManager;
    AudioComparator audioComparator;
    PracticeMaterial practiceMaterial;
    practiceMaterial.loadMaterials("phrases.txt");
    bool running = true;
    while (running) {
        ui.displayMenu();
        int choice = ui.getUserChoice();
        switch (choice) {
            case 1: {
                cout << "Starting pronunciation exercise...\n";
                string phrase = practiceMaterial.getRandomPhrase();
                cout << "Please pronounce: " << phrase << endl;
                string userAudioFile = "user_audio.wav";
                audioManager.recordAudio(userAudioFile);
                string nativeAudioFile = "native_audio.wav"; 
                float score = audioComparator.analyzePronunciation(userAudioFile, nativeAudioFile);
                string feedback = audioComparator.generateFeedback(score);
                ui.showFeedback(feedback);
                break;
            }
            case 2: {
                cout << "Exiting the application.\n";
                running = false;
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}