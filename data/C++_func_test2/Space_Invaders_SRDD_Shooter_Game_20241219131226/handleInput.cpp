void GameEngine::handleInput() {
    if (_kbhit()) { 
        char key = _getch();
        switch (key) {
            case 'a': player.moveLeft(); break;
            case 'd': player.moveRight(); break;
            case ' ': player.shoot(projectiles); break;
            case 'q': isRunning = false; break; 
        }
    }
}