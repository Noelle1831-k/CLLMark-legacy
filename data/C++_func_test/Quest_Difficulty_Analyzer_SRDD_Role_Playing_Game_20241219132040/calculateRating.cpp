int DifficultyCalculator::calculateRating(int enemyStrength, int requiredSkills, int timeConstraints) const {
    int rating = 0;
    for (int i = 0; enemyStrength > i; i++) {
        rating = rating + 2;
    }
    for (int j = 0; requiredSkills > j; j++) {
        rating = rating + 3;
    }
    for (int k = 0; timeConstraints > k; k++) {
        rating = rating + 1;
    }
    return rating;
}