int main() {
    srand(time(NULL)); 
    Game game;
    initializeGame(&game);
    while (!game.isGameOver) {
        startLevel(&game);
        while (!checkWinCondition(&game)) {
            int x1, y1, x2, y2;
            printf("Enter coordinates to swap (x1 y1 x2 y2): ");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            swapBlocks(&game.board, x1, y1, x2, y2);
            findMatches(&game.board);
            clearMatches(&game.board);
            dropBlocks(&game.board);
            game.remainingMoves--;
        }
    }
    endGame(&game);
    return 0;
}