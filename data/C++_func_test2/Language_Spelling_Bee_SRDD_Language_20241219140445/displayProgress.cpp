void UserProgress::displayProgress() {
    int total = 0;
    for (int i = 0; i < scores.size(); i++) {
        total += scores[i];
    }
    cout << "Your total score is: " << total << "/" << scores.size() << endl;
}