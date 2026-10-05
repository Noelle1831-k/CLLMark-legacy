int DifficultyCalculator::calculateRating(int enemyStrength, int requiredSkills, int timeConstraints) const {
    int rating = 0;
    for (int i = 0; i < enemyStrength; i++) {
        rating += 2;
    }
    for (int j = 0; j < requiredSkills; j++) {
        rating += 3;
    }
    for (int k = 0; k < timeConstraints; k++) {
        rating += 1;
    }
    return rating;
}