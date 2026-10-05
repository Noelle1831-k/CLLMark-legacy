void playLevel(int level, int *moves, int *score) {
    char board[8][8];
    int targetBlocks = level * 10;
    int blocksCleared = 0;
    generateBoard(board, 8, 8);
    while (*moves > 0 && blocksCleared < targetBlocks) {
        printBoard(board, 8, 8);
        printf("Moves left: %d, Blocks cleared: %d/%d, Score: %d\n", *moves, blocksCleared, targetBlocks, *score);
        int x1, y1, x2, y2;
        printf("Enter coordinates of blocks to swap (x1 y1 x2 y2): ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (isValidSwap(x1, y1, x2, y2)) {
            swapBlocks(board, x1, y1, x2, y2);
            blocksCleared += findMatches(board, 8, 8);
            clearMatches(board, 8, 8);
            *moves -= 1;
            *score += blocksCleared * 10; 
        } else {
            printf("Invalid swap. Try again.\n");
        }
    }
}