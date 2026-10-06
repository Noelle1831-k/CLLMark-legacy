void playerMove() {
    char direction;
    printf("Player is moving through the dungeon...\n");
    printf("Enter direction (N: North, S: South, E: East, W: West): ");
    scanf(" %c", &direction);
    int newX = player.posX;
    int newY = player.posY;
    switch (direction) {
        case 'N': case 'n': newX--; break;
        case 'S': case 's': newX++; break;
        case 'E': case 'e': newY++; break;
        case 'W': case 'w': newY--; break;
        default: printf("Invalid direction!\n"); return;
    }
    if (newX >= 0 && newX < DUNGEON_SIZE && newY >= 0 && newY < DUNGEON_SIZE) {
        player.posX = newX;
        player.posY = newY;
        printf("Moved to position (%d, %d)\n", player.posX, player.posY);
        handleEncounter();
    } else {
        printf("Cannot move outside the dungeon boundaries!\n");
    }
}