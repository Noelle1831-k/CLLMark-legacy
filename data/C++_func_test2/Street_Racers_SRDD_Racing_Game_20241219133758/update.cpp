void GameEngine::update() {
    cout << "Updating game state..." << endl;
    aiController.determineNextMove();
    playerCar.updatePosition();
    police.chasePlayer(playerCar);
    physics.handleCollisions();
}