void QuizApp::giveFeedback(int questionIndex, bool isCorrect) {
    if (isCorrect) {
        cout << "Correct!" << endl;
        scoreboard.updateScore(10);  
    } else {
        cout << "Incorrect!" << endl;
    }
}