void Quest::calculateDifficulty() {
    difficulty = (enemyStrength + requiredSkills * 10) / timeConstraint;
}