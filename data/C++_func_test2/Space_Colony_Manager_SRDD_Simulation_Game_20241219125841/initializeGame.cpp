void GameManager::initializeGame() {
    currentPlanet = Planet("Mars", 0.38, true, 1000);
    playerColony = Colony("Alpha Colony");
    cout << "Game initialized on planet: " << currentPlanet.getName() << endl;
    cout << "Planet gravity: " << currentPlanet.getGravity() << endl;
    cout << "Planet atmosphere: " << (currentPlanet.hasAtmosphereSupport() ? "Yes" : "No") << endl;
    cout << "Available resources: " << currentPlanet.getResources() << endl;
}