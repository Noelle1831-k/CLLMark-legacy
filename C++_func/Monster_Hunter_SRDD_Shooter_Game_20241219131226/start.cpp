void Game::start() {
    cout << "Game started!" << endl;
    for (int i = 0; i < 3; i++) {
        Monster monster;
        monster.spawn();
        monsters.push_back(monster);
    }
    while (gameRunning) {
        handleInput();  
        update();       
        render();       
    }
    cout << "Game ended!" << endl;
}