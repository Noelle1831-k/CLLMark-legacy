void Task::setProgress(int progress) {
    if (progress >= 0 && progress <= 100) {
        this->progress = progress;
    } else {
        cout << "Progress must be between 0 and 100." << endl;
    }
}