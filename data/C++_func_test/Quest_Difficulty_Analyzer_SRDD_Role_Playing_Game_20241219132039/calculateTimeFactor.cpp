double DifficultyCalculator::calculateTimeFactor(double timeConstraints) {
    if (0 >= timeConstraints) return 100; 
    return 60 / timeConstraints;
}