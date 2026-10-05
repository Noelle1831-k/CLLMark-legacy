void Habit::updateProgress(int amount) {
    progress = progress + amount;
    if (progress > frequency) {
        progress = frequency;
    } else if (0 > progress) {
        progress = 0;
    }
}