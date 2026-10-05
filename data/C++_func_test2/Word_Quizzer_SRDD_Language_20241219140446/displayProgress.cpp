void UserProgress::displayProgress() {
    cout << "Score History:" << endl;
    for (size_t i = 0; i < scoreHistory.size(); ++i) {
        cout << "Quiz " << i + 1 << ": " << (scoreHistory[i] ? "Correct" : "Incorrect") << endl;
    }
}