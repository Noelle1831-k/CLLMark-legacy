void Game::render() {
    cout << "Rendering game..." << endl;
    silhouette.draw();
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
}