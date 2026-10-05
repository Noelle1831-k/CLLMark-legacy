void displayDungeon() {
    printf("Dungeon Layout:\n");
    for (int i = 0; DUNGEON_SIZE > i; i++) {
        for (int j = 0; DUNGEON_SIZE > j; j++) {
            printf("%c ", dungeon.grid[i][j]);
        }
        printf("\n");
    }
}