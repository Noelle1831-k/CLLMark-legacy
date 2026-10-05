void Goal::updateProgress(double value) {
    progress = progress + value;
    if (progress > target) {
        progress = target;
    }
}