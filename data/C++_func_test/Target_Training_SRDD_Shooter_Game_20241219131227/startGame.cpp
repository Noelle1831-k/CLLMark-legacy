void Game::startGame() {
    cout << "Starting the game!" << endl;
    char input;
    while (true) {
        cout << "Press 'w' to move, 's' to shoot, 'r' to reload, 'q' to quit: ";
        cin >> input;
        switch (input) {
        case 'w':
            player->move();
            break;
        case 's':
            if (weapon->fire()) {
                if (target->checkHit(player.get())) {
                    scoreManager->updateScore();
                }
            }
            break;
        case 'r':
            weapon->reload();
            break;
        case 'q':
            cout << "Exiting game..." << endl;
            return;
        default:
            cout << "Invalid input!" << endl;
        }
        scoreManager->displayScore();
    }
}