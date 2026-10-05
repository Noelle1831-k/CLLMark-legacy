void LanguageApp::provideFeedback(const Exercise& exercise, const string& userAnswer) {
    Feedback feedback = exercise.checkAnswer(userAnswer);
    feedback.display();
    user.updateProgress(feedback);
}