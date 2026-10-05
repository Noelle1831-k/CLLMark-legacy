void Game::update() {
    cout << "Updating game state..." << endl;
    silhouette.checkFit();
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->rotate();
        shapes[i]->flip();
    }
}