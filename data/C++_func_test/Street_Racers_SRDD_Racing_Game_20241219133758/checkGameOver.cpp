void GameEngine::checkGameOver() {
    if (playerCar.getPositionY() >= raceTrack.getFinishLine()) {
        cout << "You reached the finish line! You win!" << endl;
        isRunning = false;
    }
    if (police.hasCaughtPlayer(playerCar)) {
        cout << "You were caught by the police! Game over!" << endl;
        isRunning = false;
    }
}