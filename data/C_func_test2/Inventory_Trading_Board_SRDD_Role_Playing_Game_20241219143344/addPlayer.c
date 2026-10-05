void addPlayer() {
    if (MAX_PLAYERS <= playerCount) {
        printf("Player limit reached. Cannot add more players.\n");
        return;
    }
    Player newPlayer;
    newPlayer.id = playerCount + 1;
    printf("Enter username: ");
    scanf("%s", newPlayer.username);
    newPlayer.rating = 5.0;
    newPlayer.inventorySize = 0;
    players[playerCount] = newPlayer;
    playerCount++;
    printf("Player %s added successfully!\n", newPlayer.username);
}