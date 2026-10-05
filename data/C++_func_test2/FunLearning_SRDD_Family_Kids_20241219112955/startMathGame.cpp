void startMathGame() {
    int score = 0, numQuestions = 5;
    for (int i = 0; i < numQuestions; i++) {
        if (runQuiz("Math") == true) {
            score++;
        }
    }
    displayMessage("Math Game Over! Your score: " + to_string(score), 1);
}