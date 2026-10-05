void GameEngine::updatePhysics() {
    physicsEngine.applyGravity(player.getCar());
    physicsEngine.handleCollisions(player.getCar(), track);
}