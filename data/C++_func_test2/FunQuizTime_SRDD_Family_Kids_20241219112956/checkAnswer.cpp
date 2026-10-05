bool Quiz::checkAnswer(int questionIndex, int userAnswer) {
    return questions[questionIndex].getAnswer() == userAnswer;
}