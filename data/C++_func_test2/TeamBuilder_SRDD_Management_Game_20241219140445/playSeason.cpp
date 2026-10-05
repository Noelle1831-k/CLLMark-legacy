void Game::playSeason() {
    cout << "Playing season..." << endl;
    Match match(myTeam, myTeam); 
    match.simulateMatch();
    match.displayResult();
}