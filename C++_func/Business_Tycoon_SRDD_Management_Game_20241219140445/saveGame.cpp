void Game::saveGame() {
    ofstream saveFile("savegame.dat");
    if (!saveFile) {
        cout << "Error saving game!" << endl;
        return;
    }
    saveFile << business.getSaveData() << endl;
    cout << "Game saved successfully!" << endl;
    saveFile.close();
}