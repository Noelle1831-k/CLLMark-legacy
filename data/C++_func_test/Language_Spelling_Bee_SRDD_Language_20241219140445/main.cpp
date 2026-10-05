int main() {
    WordDatabase wordDB;
    QuizManager quizManager;
    UserProgress userProgress;
    string language;
    int difficulty;
    cout << "Welcome to the Language Spelling Bee!" << endl;
    cout << "Select your target language: ";
    cin >> language;
    cout << "Select difficulty level (1-3): ";
    cin >> difficulty;
    wordDB.loadWords(language, difficulty);
    quizManager.setWordDatabase(&wordDB);
    quizManager.setUserProgress(&userProgress);
    char continueQuiz = 'y';
    while (continueQuiz == 'y') {
        quizManager.startQuiz();
        cout << "Do you want to try another quiz? (y/n): ";
        cin >> continueQuiz;
    }
    userProgress.displayProgress();
    cout << "Thank you for using the Language Spelling Bee!" << endl;
    return 0;
}