void MathGame::startGame() {
    scoreTracker.resetScore();
    for (int i = 0; i < 5; i++) {
        generateProblem();
        displayProblem();
        int userAnswer;
        cin >> userAnswer;
        if (checkAnswer(userAnswer)) {
            cout << "Correct!" << endl;
            updateScore(true);
        } else {
            cout << "Wrong answer!" << endl;
            updateScore(false);
        }
    }
    cout << "Game Over! Your final score is: " << scoreTracker.getScore() << endl;
}