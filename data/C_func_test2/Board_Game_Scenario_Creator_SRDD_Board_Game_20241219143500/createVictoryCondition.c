VictoryCondition *createVictoryCondition() {
    VictoryCondition *victoryCondition = (VictoryCondition *)malloc(sizeof(VictoryCondition));
    victoryCondition->condition = NULL;
    return victoryCondition;
}