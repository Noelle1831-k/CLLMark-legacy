void FlashcardSystem::startPractice(VocabularyManager& vocabularyManager, UserProfile& userProfile) {
    string word;
    for (const auto& entry : vocabularyManager.vocabulary) {
        cout << "What is the meaning of " << entry.first << "? ";
        cin.ignore();
        string meaning;
        getline(cin, meaning);
        if (meaning == entry.second) {
            cout << "Correct!" << endl;
            userProfile.addLearnedWord(entry.first);
        } else {
            cout << "Incorrect! The correct answer is: " << entry.second << endl;
        }
    }
}