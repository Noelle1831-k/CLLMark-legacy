bool Question::checkAnswer(const string& userAnswer) {
    return toLowerCase(userAnswer) == toLowerCase(correctAnswer);
}