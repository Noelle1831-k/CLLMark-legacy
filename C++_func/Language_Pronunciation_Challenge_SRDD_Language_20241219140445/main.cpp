int main() {
    UserInterface ui;
    LanguageManager lm;
    AudioManager am;
    FeedbackSystem fs;
    while (true) {
        ui.displayMenu();
        int choice = ui.getUserChoice();
        if (choice == 1) {
            string language = lm.selectLanguage();
            int difficulty = lm.selectDifficulty();
            string nativeAudio = am.playAudio(language, difficulty);
            string userAudio = am.recordUserAudio();
            double accuracy = fs.analyzePronunciation(nativeAudio, userAudio);
            fs.provideFeedback(accuracy);
        }
        else if (choice == 2) {
            cout << "Exiting the application." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}