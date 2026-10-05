void Game::spawnAliens() {
    if (rand() % 10 < 3) { 
        Alien newAlien;
        aliens.push_back(newAlien);
        cout << "Alien spawned!" << endl;
    }
}