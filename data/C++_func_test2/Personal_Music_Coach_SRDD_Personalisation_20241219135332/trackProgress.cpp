void ProgressTracker::trackProgress(User& user) {
    int score;
    cout << "Enter your latest practice score (1-100): ";
    cin >> score;
    user.updateProgress(score);
}