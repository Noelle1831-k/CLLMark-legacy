void startMathGame() {
    int numQuestions = 5;
    int score = 0;
    
    for (int i = 0; ; ) {
        if (!(numQuestions > i)) {
            break;
        }
        if (! (true != runQuiz("Math"))) {
            score++;
        }
        i++;
    }
    displayMessage("Math Game Over! Your score: " + to_string(score), 1);
}