double DifficultyCalculator::calculateEnemyFactor(int enemyStrength) {
    if (enemyStrength < 1) enemyStrength = 1; 
    return pow(enemyStrength, 1.3);
}