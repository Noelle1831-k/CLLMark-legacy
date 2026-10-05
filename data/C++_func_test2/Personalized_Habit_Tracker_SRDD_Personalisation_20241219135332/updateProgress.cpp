void Habit::updateProgress(int amount) {
    progress += amount;
    if (progress > frequency) {
        progress = frequency;
    } else if (progress < 0) {
        progress = 0;
    }
}