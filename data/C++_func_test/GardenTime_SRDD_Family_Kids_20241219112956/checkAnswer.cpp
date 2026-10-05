void Quiz::checkAnswer(string answer) {
    if (answer == correctAnswer) {
        cout << "Correct! Well done." << endl;
    } else {
        cout << "Oops! The correct answer is: " << correctAnswer << endl;
    }
}