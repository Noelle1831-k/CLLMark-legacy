int main() {
    User user;
    user.selectLanguage();
    user.selectDifficulty();
    Quiz quiz;
    quiz.loadQuestions(user.getLanguage(), user.getDifficulty());
    Feedback feedback;
    for (int i = 0; i < 10; i++) {
        quiz.displayQuestion(i);
        string userAnswer;
        cout << "Enter your answer: ";
        cin >> userAnswer;
        bool isCorrect = quiz.checkAnswer(i, userAnswer);
        feedback.giveFeedback(isCorrect);
    }
    return 0;
}