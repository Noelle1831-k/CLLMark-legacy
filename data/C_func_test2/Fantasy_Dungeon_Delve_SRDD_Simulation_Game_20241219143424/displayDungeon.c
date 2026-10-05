void displayDungeon() {
    printf("Dungeon Layout:\n");
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            printf("%c ", dungeon.grid[i][j]);
        }
        printf("\n");
    }
}