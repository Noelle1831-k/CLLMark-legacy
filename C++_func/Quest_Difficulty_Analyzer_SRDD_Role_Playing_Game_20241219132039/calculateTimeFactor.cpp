double DifficultyCalculator::calculateTimeFactor(double timeConstraints) {
    if (timeConstraints <= 0) return 100; 
    return 60 / timeConstraints;
}