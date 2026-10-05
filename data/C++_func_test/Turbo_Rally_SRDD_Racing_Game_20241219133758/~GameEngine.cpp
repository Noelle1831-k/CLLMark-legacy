GameEngine::~GameEngine() {
    delete vehicle;
    delete track;
    delete weather;
    delete physicsEngine;
    delete graphicsRenderer;
}