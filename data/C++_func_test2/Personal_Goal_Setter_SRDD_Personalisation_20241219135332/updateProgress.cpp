void Goal::updateProgress(double value) {
    progress += value;
    if (progress > target) {
        progress = target;
    }
}