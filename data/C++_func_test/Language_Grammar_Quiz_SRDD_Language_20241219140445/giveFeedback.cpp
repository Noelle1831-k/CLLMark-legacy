void Feedback::giveFeedback(bool isCorrect) {
    if (isCorrect) {
        cout << "Correct! Great job!" << endl;
    } else {
        cout << "Incorrect. Don't give up, try the next one!" << endl;
    }
}