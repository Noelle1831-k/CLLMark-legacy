void Scoreboard::displayAllGames() const {
    if (games.empty()) {
        cout << "No games available to display." << endl;
        return;
    }
    for (size_t i = 0; i < games.size(); i++) {
        games[i].displayGameInfo();
    }
}