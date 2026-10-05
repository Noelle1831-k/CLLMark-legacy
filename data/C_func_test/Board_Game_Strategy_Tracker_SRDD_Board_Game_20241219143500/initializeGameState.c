void initializeGameState(GameState *state) {
    state->moveCount = 0;
    strcpy(state->gameID, "GAME_");
    strcat(state->gameID, generateRandomID());
}