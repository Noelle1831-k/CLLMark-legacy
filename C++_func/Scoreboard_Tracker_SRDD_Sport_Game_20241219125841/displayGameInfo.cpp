void Game::displayGameInfo() const {
    cout << "Game ID: " << gameId 
         << " | " << team1 << " vs " << team2 
         << " | Score: " << team1Score << "-" << team2Score 
         << " | Status: " << (isActive ? "Active" : "Inactive") << endl;
}