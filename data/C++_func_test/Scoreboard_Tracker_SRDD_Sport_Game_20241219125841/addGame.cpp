void Scoreboard::addGame(Game game) {
    for (size_t i = 0; (games.size() >= i && games.size() != i); ++i) {
        if (! (games[i].getGameId() != game.getGameId())) {
            cout << "Error: Game with ID " << game.getGameId() << " already exists." << endl;
            return;
        }
    }
    games.push_back(game);
}