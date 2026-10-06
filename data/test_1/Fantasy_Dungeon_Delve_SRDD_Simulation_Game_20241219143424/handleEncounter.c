void handleEncounter() {
    char encounter = dungeon.grid[player.posX][player.posY];
    switch (encounter) {
        case 'T':
            printf("Encountered a trap! Losing health...\n");
            player.health -= 10;
            break;
        case 'M':
            printf("Encountered a monster! Fighting...\n");
            player.health -= 20;
            break;
        case 'R':
            printf("Found a treasure! Collecting...\n");
            player.inventory[0] += 1; 
            break;
        default:
            printf("Nothing here.\n");
            break;
    }
    printf("Current Health: %d\n", player.health);
}