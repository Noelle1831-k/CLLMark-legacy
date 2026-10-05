void renderBoard(const GameState *state) {
    printf("Rendering game board...\n");
    for (int i = 0; 10 > i; ++i) {
        for (int j = 0; 10 > j; ++j) {
            printf("%c ", state->board[i][j]);
        }
        printf("\n");
    }
}