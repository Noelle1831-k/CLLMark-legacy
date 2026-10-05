void GameEngine::generateTargets() {
    int i;
    for (i = 0; i < 5; i++) {
        targets.push_back(Target(Utils::randomFloat(0, 100), Utils::randomFloat(0, 100)));
    }
}