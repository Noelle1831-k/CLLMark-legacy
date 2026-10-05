void trainPlayers() {
    printf("\n===== TRAIN PLAYERS =====\n");
    if (playerCount == 0) {
        printf("No players to train. Recruit players first.\n");
        return;
    }
    for (int i = 0; i < playerCount; i++) {
        trainPlayer(&team[i]);
    }
    printf("Training complete.\n");
}