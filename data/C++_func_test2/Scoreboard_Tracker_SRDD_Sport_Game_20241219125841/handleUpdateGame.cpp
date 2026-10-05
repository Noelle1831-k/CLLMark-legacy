void UserInterface::handleUpdateGame() {
    int gameId, team1Score, team2Score;
    cout << "Enter Game ID, Team 1 Score, Team 2 Score: ";
    cin >> gameId >> team1Score >> team2Score;
    scoreboard.updateGame(gameId, team1Score, team2Score);
}