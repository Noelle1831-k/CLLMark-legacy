void Game::loadGame() {
    ifstream loadFile("savegame.dat");
    if (!loadFile) {
        cout << "No save data found!" << endl;
        return;
    }
    business.loadFromData(loadFile);
    cout << "Game loaded successfully!" << endl;
    loadFile.close();
}