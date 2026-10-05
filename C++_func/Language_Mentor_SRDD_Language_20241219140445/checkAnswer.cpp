Feedback Exercise::checkAnswer(const string& userAnswer) const {
    if (userAnswer == correctAnswer) {
        return Feedback("Correct!", true);
    } else {
        return Feedback("Incorrect. The correct answer was: " + correctAnswer, false);
    }
}