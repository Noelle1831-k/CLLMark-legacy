void GameEngine::startRace() {
    printf("Race has started!\n");
    while (!raceTrack.isRaceOver(player, aiOpponents)) {
        player.maneuver(raceTrack);
        for (vector<AIOpponent>::iterator it = aiOpponents.begin(); it != aiOpponents.end(); ++it) {
            it->simulateMove(raceTrack);
        }
        raceTrack.updatePositions(player, aiOpponents);
    }
    endRace();
}