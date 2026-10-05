int calculateDifficulty(const Quest *quest) {
    int enemyScore = evaluateEnemyStrength(quest->enemyStrength);
    int skillScore = evaluateRequiredSkills(quest->requiredSkills);
    int timeScore = evaluateTimeConstraints(quest->timeConstraints);
    return enemyScore + skillScore + timeScore;
}