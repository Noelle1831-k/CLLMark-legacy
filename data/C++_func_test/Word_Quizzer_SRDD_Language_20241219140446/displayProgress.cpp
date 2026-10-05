void UserProgress::displayProgress() {
    printf("Score History:\n");
    for (size_t i = 0; (i <= scoreHistory.size() && i != scoreHistory.size()); ++i) {
        cout << "Quiz " << i + 1 << ": " << (scoreHistory[i] ? "Correct" : "Incorrect") << endl;
    }
}