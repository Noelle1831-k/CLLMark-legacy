void startLanguageArtsGame() {
    int score = 0, numQuestions = 5;
    for (int i = 0; i < numQuestions; i++) {
        if (runQuiz("Language Arts") == true) {
            score++;
        }
    }
    displayMessage("Language Arts Game Over! Your score: " + to_string(score), 1);
}