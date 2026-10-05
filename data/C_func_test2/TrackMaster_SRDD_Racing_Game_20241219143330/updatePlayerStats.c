void updatePlayerStats() {
    printf("Updating player stats...\n");
    int playerXP = rand() % 500 + 100;  
    int playerLevel = playerXP / 100;    
    printf("Player XP: %d\n", playerXP);
    printf("Player level: %d\n", playerLevel);
}