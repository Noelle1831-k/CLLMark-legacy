int checkVictoryCondition(VictoryCondition *victoryCondition, int playerStatus) {
    if (playerStatus == 1) {
        printf("Victory condition met: %s\n", victoryCondition->condition);
        return 1;
    }
    return 0;
}