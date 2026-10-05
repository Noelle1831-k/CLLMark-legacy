void setVictoryCondition(VictoryCondition *victoryCondition, char *condition) {
    snprintf(victoryCondition->condition, MAX_CONDITION_LENGTH, "%s", condition);
}