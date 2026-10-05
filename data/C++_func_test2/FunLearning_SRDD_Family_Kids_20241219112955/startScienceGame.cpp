void startScienceGame() {
    int score = 0, numQuestions = 5;
    for (int i = 0; i < numQuestions; i++) {
        if (runQuiz("Science") == true) {
            score++;
        }
    }
    displayMessage("Science Game Over! Your score: " + to_string(score), 1);
}