void Scoreboard::updateGame(int gameId, int team1Score, int team2Score) {
    Game* game = findGameById(gameId);
    if (game != nullptr) {
        game->updateScore(team1Score, team2Score);
    } else {
        cout << "Error: Game with ID " << gameId << " not found." << endl;
    }
}