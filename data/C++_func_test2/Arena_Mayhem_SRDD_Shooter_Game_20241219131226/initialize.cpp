void GameEngine::initialize() {
    player = Player();
    arena = Arena();
    weapons.push_back(Weapon("Pistol"));
    weapons.push_back(Weapon("Shotgun"));
    powerUps.push_back(PowerUp("Speed Boost"));
    powerUps.push_back(PowerUp("Shield"));
}