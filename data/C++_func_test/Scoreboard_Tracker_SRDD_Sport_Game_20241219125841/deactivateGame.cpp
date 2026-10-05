void Scoreboard::deactivateGame(int gameId) {
    Game* game = findGameById(gameId);
    if (game != nullptr) {
        game->deactivateGame();
    } else {
        cout << "Error: Game with ID " << gameId << " not found." << endl;
    }
}