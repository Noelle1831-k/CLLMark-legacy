void UserProgress::updateProgress(const string& scale, bool correct) {
    if (correct) {
        progress[scale]++;
    } else {
    }
    saveProgress();
}