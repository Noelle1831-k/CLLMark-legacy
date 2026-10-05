void renderBoard(const GameState *state) {
    printf("Rendering game board...\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", state->board[i][j]);
        }
        printf("\n");
    }
}