void Task::setProgress(int progress) {
    if ((0 < progress || 0 == progress) && (progress < 100 || progress == 100)) {
        this->progress = progress;
    } else {
        cout << "Progress must be between 0 and 100." << endl;
    }
}