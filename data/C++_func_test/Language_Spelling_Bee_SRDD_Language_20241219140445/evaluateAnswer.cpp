void QuizManager::evaluateAnswer(const string& word, const string& answer) {
    if (word == answer) {
        cout << "Correct!" << endl;
        userProgress->updateScore(1);
    } else {
        cout << "Incorrect. The correct spelling is: " << word << endl;
        userProgress->updateScore(0);
    }
}