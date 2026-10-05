int main() {
    VocabularyManager vocabularyManager;
    UserProfile userProfile;
    FlashcardSystem flashcardSystem;
    Utils utils;
    cout << "Welcome to the Vocabulary Builder Application!" << endl;
    cout << "---------------------------------------------" << endl;
    if (!utils.loadUserProfile(userProfile)) {
        cout << "No previous user data found. Creating a new profile..." << endl;
        userProfile.createNewProfile();
    }
    int choice = 0;
    while (choice != 5) {
        cout << "\nMain Menu:" << endl;
        cout << "1. Add a New Word" << endl;
        cout << "2. Practice Words" << endl;
        cout << "3. View Learned Words" << endl;
        cout << "4. View Vocabulary List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string word, meaning;
                cout << "Enter the word: ";
                cin >> word;
                cout << "Enter the meaning: ";
                cin.ignore();
                getline(cin, meaning);
                vocabularyManager.addWord(word, meaning);
                break;
            }
            case 2:
                flashcardSystem.startPractice(vocabularyManager, userProfile);
                break;
            case 3:
                userProfile.viewLearnedWords();
                break;
            case 4:
                vocabularyManager.displayVocabulary();
                break;
            case 5:
                cout << "Exiting the application. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    utils.saveUserProfile(userProfile);
    return 0;
}