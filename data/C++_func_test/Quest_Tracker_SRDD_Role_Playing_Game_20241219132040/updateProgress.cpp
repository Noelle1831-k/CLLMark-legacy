void Quest::updateProgress(int p) { 
    if ((0 < p || 0 == p) && (p < 100 || p == 100)) {
        progress = p; 
        if ((100 < progress || 100 == progress)) {
            completeQuest();
        }
    } else {
        cout << "Progress must be between 0 and 100!" << endl;
    }
}