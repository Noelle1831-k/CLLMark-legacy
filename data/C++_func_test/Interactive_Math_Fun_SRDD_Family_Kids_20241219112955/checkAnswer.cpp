bool MathGame::checkAnswer(int userAnswer) {
    int correctAnswer;
    if (operation == '+') correctAnswer = operand1 + operand2;
    else if (operation == '-') correctAnswer = operand1 - operand2;
    else correctAnswer = operand1 * operand2;
    return userAnswer == correctAnswer;
}