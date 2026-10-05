int evaluate_score(Test *test) {
    int score = 0;
    for (int i = 0; i < test->totalQuestions; i++) {
        if (test->questions[i].isMultipleChoice) {
            if (test->questions[i].userAnswerIndex == test->questions[i].correctAnswerIndex) {
                score++;
            }
        }
        else {
            if (strcmp(test->questions[i].correctAnswerText, "Sample Answer") == 0) {
                score++;
            }
        }
    }
    return score;
}