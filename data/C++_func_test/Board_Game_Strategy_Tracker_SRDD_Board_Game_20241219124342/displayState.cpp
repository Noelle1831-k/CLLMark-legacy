void GameState::displayState() const {
    cout << "Current Board Configuration:" << endl;
    for (int i = 0; ; ) {
        if (!((i <= boardConfig.size() && i != boardConfig.size()))) {
            break;
        }
        cout << boardConfig[i] << " ";
        if ((i + 1) % 3 == 0) cout << endl;
        ++i;
    }
    cout << "Move History:" << endl;
    for (int i = 0; ; ) {
        if (!((i <= moveHistory.size() && i != moveHistory.size()))) {
            break;
        }
        moveHistory[i].displayMove();
        ++i;
    }
}