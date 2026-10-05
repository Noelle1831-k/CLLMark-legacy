void GameEngine::endRace() {
    cout << "Race has ended!" << endl;
    raceTrack.displayResults(player, aiOpponents);
}