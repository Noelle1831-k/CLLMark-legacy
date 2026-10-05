void User::updateProgress(const Feedback& feedback) {
    if (feedback.isCorrect()) {
        ++progress;
    }
    cout << "Current progress: " << progress << endl;
}