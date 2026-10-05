void Quest::updateProgress(int p) { 
    if (p >= 0 && p <= 100) {
        progress = p; 
        if (progress >= 100) {
            completeQuest();
        }
    } else {
        cout << "Progress must be between 0 and 100!" << endl;
    }
}