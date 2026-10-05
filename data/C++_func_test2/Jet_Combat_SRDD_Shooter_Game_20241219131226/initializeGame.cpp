void Game::initializeGame() {
    cout << "Initializing game..." << endl;
    playerJet = Jet("Falcon", 300, 80, 100);
    missions.push_back(Mission("Mission 1", 1));
    missions.push_back(Mission("Mission 2", 2));
    missions.push_back(Mission("Boss Battle", 5));
    displayMainMenu();
}