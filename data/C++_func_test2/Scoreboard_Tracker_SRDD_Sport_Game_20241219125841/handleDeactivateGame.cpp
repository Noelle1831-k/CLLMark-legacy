void UserInterface::handleDeactivateGame() {
    int gameId;
    cout << "Enter Game ID to deactivate: ";
    cin >> gameId;
    scoreboard.deactivateGame(gameId);
}