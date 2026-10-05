void GameState::displayState() const {
    cout << "Current Board Configuration:" << endl;
    for (int i = 0; i < boardConfig.size(); i++) {
        cout << boardConfig[i] << " ";
        if ((i + 1) % 3 == 0) cout << endl;
    }
    cout << "Move History:" << endl;
    for (int i = 0; i < moveHistory.size(); i++) {
        moveHistory[i].displayMove();
    }
}