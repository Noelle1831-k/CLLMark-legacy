void ScaleTrainer::provideFeedback(const string& userInput, const string& correctScale, UserProgress& userProgress) {
    if (Utils::validateInput(userInput)) {
        if (userInput == correctScale) {
            cout << "Correct! Great job!" << endl;
            userProgress.updateProgress(correctScale, true);
        } else {
            cout << "Incorrect. The correct scale was: " << correctScale << endl;
            userProgress.updateProgress(correctScale, false);
        }
    } else {
        cout << "Invalid input. Please enter a valid scale name next time." << endl;
    }
}