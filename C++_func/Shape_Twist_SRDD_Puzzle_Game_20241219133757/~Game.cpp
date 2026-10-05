Game::~Game() {
    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
}