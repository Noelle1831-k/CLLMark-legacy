int main() {
    Phrasebook phrasebook;
    Quiz quiz;
    Menu menu;
    Audio audio;
    string userInput;
    phrasebook.loadSampleData();
    while (true) {
        menu.displayMainMenu();
        cout << "Please select an option: ";
        cin >> userInput;
        if (userInput == "1") {
            phrasebook.displayCategories();
        } else if (userInput == "2") {
            quiz.startQuiz(phrasebook);
        } else if (userInput == "3") {
            phrasebook.addCustomPhrase();
        } else if (userInput == "4") {
            audio.playPhraseAudio(phrasebook);
        } else if (userInput == "5") {
            cout << "Exiting program..." << endl;
            break;
        } else {
            cout << "Invalid input, please try again." << endl;
        }
    }
    return 0;
}