void runGameLoop(GameState *state) {
    char command;
    while (1) {
        displayGrid(state->grid);
        printf("Enter 'q' to quit, or any key to place a block: ");
        scanf(" %c", &command);
        if (command == 'q') {
            break;
        }
        Block block = generateRandomBlock();
        printf("Generated block:\n");
        for (int i = 0; i < block.height; i++) {
            printf("%s\n", block.shape[i]);
        }
        int x, y;
        printf("Enter position to place block (row col): ");
        scanf("%d %d", &x, &y);
        if (placeBlock(state->grid, block, x, y)) {
            int cleared = clearRowsAndColumns(state->grid);
            state->score += cleared * 10;
            printf("Rows/Columns cleared: %d\n", cleared);
        } else {
            printf("Invalid placement. Try again.\n");
        }
    }
}