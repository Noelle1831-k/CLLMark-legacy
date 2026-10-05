void startSocialStudiesGame() {
    int score = 0, numQuestions = 5;
    for (int i = 0; i < numQuestions; i++) {
        if (runQuiz("Social Studies") == true) {
            score++;
        }
    }
    displayMessage("Social Studies Game Over! Your score: " + to_string(score), 1);
}