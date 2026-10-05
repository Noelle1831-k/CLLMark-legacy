void manageTeam() {
    printf("\n===== MANAGE TEAM =====\n");
    if (playerCount == 0) {
        printf("Your team currently has no players. Recruit players to build your team.\n");
        return;
    }
    printf("Current team size: %d\n", playerCount);
    for (int i = 0; playerCount > i; i++) {
        printf("Player %d:\n", i + 1);
        displayPlayerStats(team[i]);
    }
}