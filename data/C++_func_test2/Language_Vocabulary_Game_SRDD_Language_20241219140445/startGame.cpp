void VocabularyGame::startGame(UserProfile &user, ProgressTracker &progress) {
    VocabularyData vocabData;
    vector<string> vocabulary = vocabData.getVocabulary(user.getLanguage());
    if (vocabulary.empty()) {
        cout << "No vocabulary available for the selected language!" << endl;
        return;
    }
    int difficulty = user.getDifficulty();
    cout << "Starting the game in " << user.getLanguage() << " with difficulty " << difficulty << endl;
    int gameType = rand() % 3;  
    if (gameType == 0) {
        wordMatching(vocabulary, difficulty, progress);
    }
    else if (gameType == 1) {
        pictureLabeling(vocabulary, difficulty, progress);
    }
    else if (gameType == 2) {
        wordAssociation(vocabulary, difficulty, progress);
    }
}