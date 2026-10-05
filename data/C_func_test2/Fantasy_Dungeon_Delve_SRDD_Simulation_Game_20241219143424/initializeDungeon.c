void initializeDungeon() {
    printf("Generating dungeon...\n");
    srand(time(NULL));
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            int randElement = rand() % 4;
            switch (randElement) {
                case 0: dungeon.grid[i][j] = 'T'; break; 
                case 1: dungeon.grid[i][j] = 'M'; break; 
                case 2: dungeon.grid[i][j] = 'R'; break; 
                default: dungeon.grid[i][j] = '.'; break; 
            }
        }
    }
    printf("Dungeon created successfully.\n");
}