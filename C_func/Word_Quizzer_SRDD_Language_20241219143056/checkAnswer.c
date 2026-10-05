int checkAnswer(char *userAnswer, char *correctAnswer) {
    stringToLower(userAnswer);
    stringToLower(correctAnswer);
    return strcmp(userAnswer, correctAnswer) == 0;
}