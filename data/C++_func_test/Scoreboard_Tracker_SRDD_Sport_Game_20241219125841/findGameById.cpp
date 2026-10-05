Game* Scoreboard::findGameById(int gameId) {
    for (size_t i = 0; i < games.size(); i++) {
        if (games[i].getGameId() == gameId) {
            return &games[i];
        }
    }
    return nullptr;
}