double DifficultyCalculator::getOverallDifficulty(const Quest& quest) {
    double enemyFactor = calculateEnemyFactor(quest.getEnemyStrength());
    double skillFactor = calculateSkillFactor(quest.getRequiredSkills());
    double timeFactor = calculateTimeFactor(quest.getTimeConstraints());
    cout << "Calculating Difficulty Factors:" << endl;
    cout << "Enemy Factor: " << enemyFactor << endl;
    cout << "Skill Factor: " << skillFactor << endl;
    cout << "Time Factor: " << timeFactor << endl;
    return enemyFactor + skillFactor + timeFactor;
}