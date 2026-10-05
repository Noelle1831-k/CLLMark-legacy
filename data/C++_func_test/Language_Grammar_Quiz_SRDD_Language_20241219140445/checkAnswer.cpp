bool Quiz::checkAnswer(int index, const string& answer) {
    return questions[index].getCorrectAnswer() == answer;
}