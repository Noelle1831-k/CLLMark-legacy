void updatePlayerPositions(Player players[], int playerCount, Arena *arena) {
    for (int i = 0; i < playerCount; i++) {
        players[i].x += randomMovement(); 
        players[i].y += randomMovement();
        if (!isInsideArena(arena, players[i].x, players[i].y)) {
            players[i].x = rand() % arena->width;
            players[i].y = rand() % arena->height;
        }
        printf("Player %d moved to (%d, %d)\n", players[i].id, players[i].x, players[i].y);
    }
}