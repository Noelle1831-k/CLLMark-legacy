void GameEngine::updateState() {
    physicsEngine.calculateTraction(playerCar.getTireGrip());
    scoreManager.updateScore(playerCar.getDriftDistance(), playerCar.getDriftAngle());
    if (playerCar.getSpeed() > 200.0f) {
        cout << "Speeding! Bonus points for going over 200 km/h!" << endl;
    }
    if (playerCar.getSpeed() == 0 && playerCar.getDriftDistance() == 0) {
        currentState = GAME_OVER;
    }
}