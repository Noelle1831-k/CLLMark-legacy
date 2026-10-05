void WordQuizzer::startQuiz() {
    selectLanguage();
    selectDifficulty();
    Question question;
    question.generateQuestion(language, difficulty, database);
    string userAnswer;
    cout << "Enter your answer: ";
    cin >> userAnswer;
    if (question.checkAnswer(userAnswer)) {
        cout << "Correct!" << endl;
        progress.updateProgress(true);
    } else {
        cout << "Incorrect. The correct answer was: " << question.getCorrectAnswer() << endl;
        progress.updateProgress(false);
    }
}