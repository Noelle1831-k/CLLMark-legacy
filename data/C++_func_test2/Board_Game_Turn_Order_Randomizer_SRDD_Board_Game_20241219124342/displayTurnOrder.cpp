void GameManager::displayTurnOrder() const {
    cout << "\nRandomized Turn Order:" << endl;
    for (size_t i = 0; i < players.size(); i++) {
        cout << "Turn " << players[i].getTurnOrder() << ": " << players[i].getName() << endl;
    }
}