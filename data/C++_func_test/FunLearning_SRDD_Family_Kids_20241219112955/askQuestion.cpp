bool askQuestion(string question, string correctAnswer) {
    string answer;
    cout << question << endl;
    cout << "Your answer: ";
    cin >> answer;
    if (answer == correctAnswer) {
        displayMessage("Correct!", 1);
        return true;
    } else {
        displayMessage("Incorrect! The correct answer was: " + correctAnswer, 0);
        return false;
    }
}