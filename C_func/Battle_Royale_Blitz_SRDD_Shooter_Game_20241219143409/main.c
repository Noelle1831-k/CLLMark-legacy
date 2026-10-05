int main() {
    srand(time(NULL)); 
    printf("Welcome to Battle Royale Blitz!\n");
    Player players[MAX_PLAYERS];
    Item items[MAX_ITEMS];
    Arena arena;
    initializeArena(&arena, 100, 100); 
    int playerCount = initializePlayers(players, MAX_PLAYERS);
    initializeItems(items, MAX_ITEMS);
    assignTeams(players, playerCount);
    while (playerCount > 1) {
        printf("\n--- Game Loop ---\n");
        shrinkArena(&arena);
        updatePlayerPositions(players, playerCount, &arena);
        resolvePlayerCollisions(players, &playerCount);
        updateItemCollection(players, items, playerCount, MAX_ITEMS);
    }
    if (playerCount == 1) {
        printf("Player %d is the winner!\n", players[0].id);
    } else {
        printf("No winner, everyone is dead.\n");
    }
    return 0;
}