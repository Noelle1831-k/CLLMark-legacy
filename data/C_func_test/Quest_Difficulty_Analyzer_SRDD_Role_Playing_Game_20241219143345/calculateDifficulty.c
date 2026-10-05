int calculateDifficulty(const Quest *quest) {
    int enemyScore = evaluateEnemyStrength(quest->enemyStrength), skillScore = evaluateRequiredSkills(quest->requiredSkills), timeScore = evaluateTimeConstraints(quest->timeConstraints);


    return enemyScore + skillScore + timeScore;
}