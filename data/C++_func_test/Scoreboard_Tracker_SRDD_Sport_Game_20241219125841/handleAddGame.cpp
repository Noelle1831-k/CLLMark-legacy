void UserInterface::handleAddGame() {
    int gameId;
    string team1, team2;
    cout << "Enter Game ID, Team 1, Team 2: ";
    cin >> gameId >> team1 >> team2;
    scoreboard.addGame(Game(gameId, team1, team2));
}