int main() {
    displayWelcomeMessage();
    displayInstructions();
    Grid gameGrid;
    Pattern pattern;
    Block blocks[MAX_BLOCKS];
    initializeGrid(&gameGrid, GRID_SIZE, GRID_SIZE);
    generatePattern(&pattern, GRID_SIZE, GRID_SIZE);
    loadBlocks(blocks, MAX_BLOCKS);
    int gameOver = 0;
    while (!gameOver) {
        printGrid(&gameGrid);
        printPattern(&pattern);
        int blockIndex, rotation;
        printf("Enter block index to place (0 to %d): ", MAX_BLOCKS - 1);
        scanf("%d", &blockIndex);
        printf("Enter rotation angle (0, 90, 180, 270): ");
        scanf("%d", &rotation);
        if (placeBlock(&gameGrid, &blocks[blockIndex], rotation)) {
            printf("Block placed successfully!\n");
        } else {
            printf("Invalid placement. Try again.\n");
        }
        if (isPatternComplete(&gameGrid, &pattern)) {
            printf("Congratulations! You completed the pattern!\n");
            gameOver = 1;
        }
    }
    printf("Thanks for playing the Block Twist Challenge!\n");
    return 0;
}