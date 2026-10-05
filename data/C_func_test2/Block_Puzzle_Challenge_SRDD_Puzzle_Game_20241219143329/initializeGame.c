void initializeGame(GameState *state) {
    initializeGrid(state->grid);
    state->score = 0;
    state->level = 1;
}